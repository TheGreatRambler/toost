make clean
if [[ "$1" == "web" ]];
then
	make PLATFORM=web BUILD=release -j8
	rm -rf bin/src
	zip -9r toost_web.zip bin
else
	case $(uname | tr '[:upper:]' '[:lower:]') in
	  linux*)
		make BUILD=release -j8
		strip -s bin/toost
		cp -r os_skeletons/debian_skeleton/ toost_debian
		mkdir toost_debian/usr/bin
		mv bin/toost toost_debian/usr/bin
		mkdir toost_debian/usr/share/toost
		cp -r fonts toost_debian/usr/share/toost
		cp -r img toost_debian/usr/share/toost
		dpkg-deb --build toost_debian toost_debian.deb
		rm -rf toost_debian
		;;
	  darwin*)
		make BUILD=release -j8
		strip bin/toost
		cp -r os_skeletons/mac_skeleton/ toost.app
		mkdir toost.app/Contents/MacOS
		cp bin/toost toost.app/Contents/MacOS
		mkdir toost.app/Contents/share
		cp -r fonts toost.app/Contents/share
		cp -r img toost.app/Contents/share
		dylibbundler -od -b -x toost.app/Contents/MacOS/toost -d toost.app/Contents/libs/
		#zip -9r toost_mac.zip toost.app
		#rm -rf toost.app
		;;
	  msys*|mingw*)
		make BUILD=release -j8
		rm -rf bin/src
		strip -s bin/toost.exe
		zip -9r toost_windows.zip bin fonts img
		;;
	  *)
		echo "OS not recognized"
		;;
	esac
fi
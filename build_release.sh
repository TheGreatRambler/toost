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
		strip -s bin/toost
		cp -r os_skeletons/mac_skeleton/ toost_mac.app
		mkdir toost_mac.app/Contents/MacOS
		cp bin/toost toost_mac.app/Contents/MacOS
		mkdir toost_mac.app/Contents/share
		cp -r fonts toost_mac.app/Contents/share
		cp -r img toost_mac.app/Contents/share
		dylibbundler -od -b -x toost_mac.app/Contents/MacOS/switas -d toost_mac.app/Contents/libs/
		zip -9r toost_mac.zip toost_mac.app
		rm -rf toost_mac.app
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
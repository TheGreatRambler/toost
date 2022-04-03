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
		export TRAVIS_OS_NAME=osx
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
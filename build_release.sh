make clean
if [[ "$1" == "web" ]];
then
	make PLATFORM=web BUILD=release
	rm -rf bin/src
	zip -9r build_web.zip bin
else
	make BUILD=release
	rm -rf bin/src
	zip -9r build.zip bin fonts img
fi
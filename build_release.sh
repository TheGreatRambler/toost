make clean
if [[ "$1" == "web" ]];
then
	make PLATFORM=web BUILD=release
	rm -rf bin/src
	zip -9r toost_web.zip bin
else
	make BUILD=release
	rm -rf bin/src
	strip -s bin/toost.exe
	zip -9r toost.zip bin fonts img
fi
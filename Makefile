export CGO_ENABLED=1
export WDIR=${PWD}

all: linux windows

linux:
	GOOS=linux  CGO_CFLAGS="-I${WDIR}/include"  CGO_LDFLAGS="-L${WDIR}/lib/Linux -Wl,-rpath=${WDIR}/lib/Linux -lhcnetsdk" go build -ldflags "-s -w" -o build/linux/hik main.go
	cp lib/Linux/libhcnetsdk.so build/linux/
	cp lib/Linux/libHCCore.so build/linux/
	cp lib/Linux/libhpr.so build/linux/
	cp -r lib/Linux/HCNetSDKCom/ build/linux/

windows:
	CGO_LDFLAGS_ALLOW=".*" CGO_CFLAGS="-I${WDIR}/include" CGO_LDFLAGS="-L${WDIR}/lib/Windows -Wl,--enable-stdcall-fixup,-rpath=${WDIR}/lib/Windows -lHCNetSDK" GOOS=windows CC=x86_64-w64-mingw32-gcc CXX=x86_64-w64-mingw32-g++ go build -ldflags "-s -w" -o build/Windows/hik.exe main.go
	cp -r lib/Windows/ build/

clean:
	rm -r build/


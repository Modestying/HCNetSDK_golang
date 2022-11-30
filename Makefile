export CGO_ENABLED=1
export WDIR=${PWD}

all: linux windows

linux:
	cp lib/Linux/libhcnetsdk.so build/
	cp lib/Linux/libHCCore.so build/
	cp lib/Linux/libhpr.so build/
	cp -r lib/Linux/HCNetSDKCom/ build/
	GOOS=linux  CGO_CFLAGS="-I${WDIR}/include"  CGO_LDFLAGS="-L${WDIR}/build -Wl,-rpath=${WDIR}/build -lhcnetsdk" go build -ldflags "-s -w" -o build/hik main.go

windows:
	cp -r lib/Windows/ build/
	CGO_LDFLAGS_ALLOW=".*" CGO_CFLAGS="-I${WDIR}/include" CGO_LDFLAGS="-L${WDIR}/build -Wl,--enable-stdcall-fixup,-rpath=${WDIR}/build -lHCNetSDK -lHCCore" GOOS=windows CC=x86_64-w64-mingw32-gcc CXX=x86_64-w64-mingw32-g++ go build -ldflags "-s -w" -o build/hik.exe main.go

clean:
	rm -r build


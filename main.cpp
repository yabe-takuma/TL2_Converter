#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include "windows.h"

//コマンドライン引数
enum Argument {
	kApplicationPath,     //アプリケーションのパス
	kFilePath,            //渡されたファイルのパス

	NumArgument
};

int main(int argc,char* argv[])
{
	
	assert(argc >= NumArgument);


	HRESULT hr = CoInitializeEx(nullptr,COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));
	TextureConverter textureConverter;
	textureConverter.ConvertTextureWICToDDS(argv[kFilePath]);

	
	CoUninitialize();
	system("pause");
	return 0;

}
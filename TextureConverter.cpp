#include "TextureConverter.h"
#include <windows.h>
using namespace DirectX;

TextureConverter::TextureConverter()
{
}

TextureConverter::~TextureConverter()
{
}

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	// テクスチャファイルを読み込む
	std::wstring wFilePath = ConvertMultiByteStringToWideString(filePath);

	///DDS形式に変換して書き出す
	HRESULT result = LoadFromWICFile(wFilePath.c_str(), WIC_FLAGS_NONE,&metadata_,scratchImage_);
	assert(SUCCEEDED(result));
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//ファイルパスをワイド形式に変換

	//テクスチャを読み込む

}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}

#pragma once
#include <string>
#include "externals/DirectXTex/DirectXTex.h"

class TextureConverter
{
public:
	TextureConverter();
	~TextureConverter();

	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	/// <summary>
	/// テクスチャファイルの読み込み
	/// </summary>
	/// <param name="filePath"></param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// マルチワイド文字をワイド文字に変換する
	/// </summary>
	/// <param name="mString"></param>
	/// <returns></returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	DirectX::TexMetadata metadata_;

	DirectX::ScratchImage scratchImage_;
	
};

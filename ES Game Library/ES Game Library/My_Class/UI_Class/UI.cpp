#include"UI.h"

void UI::Initialize()
{
	//!ファイルをダウンロードさせず、プログラムで読み込みフォント作成
	AddFontResourceEx(_T("font/thirteen-pixel-fonts/thirteen_pixel_fonts.ttf"), FR_PRIVATE, nullptr);
	font       = GraphicsDevice.CreateSpriteFont(_T("Thirteen Pixel Fonts"), font_size);
	score_font = GraphicsDevice.CreateSpriteFont(_T("Thirteen Pixel Fonts"), score_font_size);
}

void UI::Update()
{
	TimeLeft();
}

void UI::Draw()
{
	SpriteBatch.DrawString(font, time_pos , Color_White, _T("%d"), time);

	SpriteBatch.DrawString(score_font,score_pos, Color_White, _T("SCORE:%d"), SceneManager::Instance().GetScore());
}

void UI::TimeLeft() {
	if (time > MIN_TIME) {
		if (frame < MAX_FRAME)
			frame++;
		else {
			time--;
			frame = MIN_FRAME;
		}
	}

}

#include"UI.h"

void UI::Initialize()
{
	//!�t�@�C�����_�E�����[�h�������A�v���O�����œǂݍ��݃t�H���g�쐬
	AddFontResourceEx(_T("font/thirteen-pixel-fonts/thirteen_pixel_fonts.ttf"), FR_PRIVATE, nullptr);
	font = GraphicsDevice.CreateSpriteFont(_T("Thirteen Pixel Fonts"), 90);
}

void UI::Update()
{
	TimeLeft();
}

void UI::Draw()
{
	SpriteBatch.DrawString(font, Vector2(600, 0), Color_White, _T("%d"), time);
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

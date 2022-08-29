// Copyright (c) 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "waveshareEmulator.h"
#include "dataBuffer.h"
#include "bits.h"
#include "fonts.h"


WaveshareEmulator::WaveshareEmulator(XLibDisplay* xlibDisplay, ulong* winIndex)
  :XLibWindow(xlibDisplay,winIndex), _PaintBuffer()
{
	_EGC = new WsEInkGC(__WIDTH, __HEIGHT);
}

void WaveshareEmulator::Init()
{
	XLibWindow::Init();
	_PaintBuffer.SetSize(__BUFFER_LENGTH);
	_PaintBuffer.Clear(0,  0x00);
	_EGC->GetCanvas()->AttachImageBuffer(_PaintBuffer.GetDataPointer(),__BUFFER_LENGTH);

	Test();
}

void WaveshareEmulator::OnPaint(shared_ptr<XLibGC> _GC)
{
	int width  = 128;
	int height = 296;

	uint windowWidth  = 0;
	uint windowHeight = 0;
	uint borderWidth  = 0;

    this->GetXLibDisplay()->GetWindowSize(this, windowWidth, windowHeight, borderWidth);
    int startBorderX = windowHeight / 2 - width  * __SCALE / 2;
    int startBorderY = windowWidth  / 2 - height * __SCALE / 2;

	_GC->SetForeground(0xE0, 0xAF, 0xFF);
	_GC->Rectangle(startBorderY, startBorderX, height*__SCALE+1, width*__SCALE+1);

	uint32_t bufferLength = _PaintBuffer.GetSize();
	uint32_t row, column, i,j;
	column = height-1;
	for (row = 0, j = 0, i = 0; i < bufferLength; i++, j++)
	{
		if (j == 16)
		{
			row = 0;
			j   = 0;
			column--;
		}
		auto value = _PaintBuffer.GetValue(i);
		for (int bit = 0; bit < 8; bit++)
		{
			if (__IS_SET_BIT(value,8-(bit+1)))
				_GC->SetForeground(0, 0, 0);
			else
				_GC->SetForeground(0xFF, 0xFF, 0xD0);

			auto x = startBorderY + column*__SCALE + 1;
			auto y = startBorderX + row*__SCALE + 1;

			this->DrawPoint(_GC, x, y);

			row++;
		}
	}
}

void WaveshareEmulator::DrawPoint(shared_ptr<XLibGC> _GC, int x, int y)
{
	if (__SCALE == 1)
		_GC->Point(x, y);

	if (__SCALE == 2)
	{
	  _GC->Point(x,   y);
	  _GC->Point(x+1, y);
	  _GC->Point(x,   y+1);
	  _GC->Point(x+1, y+1);
	}

	if (__SCALE == 3)
	{
		_GC->Point(x,   y);
		_GC->Point(x+1, y);
		_GC->Point(x+2, y);

		_GC->Point(x,   y+1);
		_GC->Point(x+1, y+1);
		_GC->Point(x+2, y+1);

		_GC->Point(x,   y+2);
		_GC->Point(x+1, y+2);
		_GC->Point(x+2, y+2);
	}
}


void WaveshareEmulator::Run()
{
	auto xlibDisplay = new XLibDisplay();
	xlibDisplay->Init();


	auto window = xlibDisplay->CreateSimpleWindow<WaveshareEmulator>();
	window->Show();

	XLibEventManager::Listen(xlibDisplay);

	delete xlibDisplay;
}

void WaveshareEmulator::Test()
{
	TestGC_01();

}

void WaveshareEmulator::TestGC_01()
{
	Font8  font8;
	Font12 font12;
	Font16 font16;
	Font20 font20;
	Font24 font24;

	for (int i = 10; i <=100; )
	{
		_EGC->DrawPoint(10, i);
		i += 5;
	}
	_EGC->Clear();

	_EGC->SetIsDrawFill(1);
	_EGC->DrawLine(10, 10, 200, 10);

	_EGC->DrawRectangle(20, 20, 80, 80);
	_EGC->DrawLine(20, 20, 80, 80);
	_EGC->DrawLine(20, 80, 80, 20);

	_EGC->DrawCircle(150, 65, 50);
	_EGC->DrawChar(&font16 ,220, 10, 'A');

	_EGC->DrawString(&font24, 110, 55, "Label");

}

WaveshareEmulator::~WaveshareEmulator()
{

}



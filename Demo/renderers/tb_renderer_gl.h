// ================================================================================
// == This file is a part of TinkerBell UI Toolkit. (C) 2011-2013, Emil Seger�s  ==
// ==                   See tinkerbell.h for more information.                   ==
// ================================================================================

#ifndef TB_RENDERER_GL_H
#define TB_RENDERER_GL_H

#ifdef USE_GLES
#include <EGL/egl.h>
#include <GLES/gl.h>
#elif defined(_WIN32)
#include <windows.h> // make gl.h compile
#include <GL/gl.h>
#elif defined(MACOSX)
#include <OpenGL/gl.h>
#elif defined(ANDROID)
#include <GLES/gl.h>
//#include <GLES2/gl2.h>
//#include <GLES2/gl2ext.h>
#else
#include <GL/gl.h>
#endif

#include "tb_renderer.h"

namespace tinkerbell {

class TBBitmapGL : public TBBitmap
{
public:
	TBBitmapGL();
	~TBBitmapGL();
	bool Init(int width, int height, uint32 *data);
	virtual int Width() { return m_w; }
	virtual int Height() { return m_h; }
	virtual void SetData(uint32 *data);
public:
	int m_w, m_h;
	GLuint m_texture;
};

class TBRendererGL : public TBRenderer
{
public:
	TBRendererGL();

	// == TBRenderer ==============================================

	virtual void BeginPaint(int render_target_w, int render_target_h);
	virtual void EndPaint();

	virtual void Translate(int x, int y);
	virtual void SetOpacity(float opacity);
	virtual float GetOpacity();
	virtual TBRect SetClipRect(const TBRect &rect, bool add_to_current);
	virtual TBRect GetClipRect();
	virtual void DrawBitmap(const TBRect &dst_rect, const TBRect &src_rect, TBBitmapFragment *bitmap_fragment);
	virtual void DrawBitmap(const TBRect &dst_rect, const TBRect &src_rect, TBBitmap *bitmap);
	virtual void DrawBitmapColored(const TBRect &dst_rect, const TBRect &src_rect, const TBColor &color, TBBitmapFragment *bitmap_fragment);
	virtual void DrawBitmapColored(const TBRect &dst_rect, const TBRect &src_rect, const TBColor &color, TBBitmap *bitmap);
	virtual void DrawBitmapTile(const TBRect &dst_rect, TBBitmap *bitmap);
	virtual void DrawRect(const TBRect &dst_rect, const TBColor &color);
	virtual void DrawRectFill(const TBRect &dst_rect, const TBColor &color);
	virtual void FlushBitmapFragment(TBBitmapFragment *bitmap_fragment);

	virtual TBBitmap *CreateBitmap(int width, int height, uint32 *data);
public:
	uint8 m_opacity;
	TBRect m_screen_rect;
	TBRect m_clip_rect;
	int m_translation_x;
	int m_translation_y;
};

}; // namespace tinkerbell

#endif // TB_RENDERER_GL_H
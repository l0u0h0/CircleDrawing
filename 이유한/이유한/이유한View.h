
// 이유한View.h: C이유한View 클래스의 인터페이스
//

#pragma once


class C이유한View : public CView
{
protected: // serialization에서만 만들어집니다.
	C이유한View() noexcept;
	DECLARE_DYNCREATE(C이유한View)

// 특성입니다.
public:
	C이유한Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~C이유한View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_pt1;
	CPoint m_pt2;
	int m_Radius;
	COLORREF m_brushColor;
	int Length(CPoint m_pt1, CPoint m_pt2);
};

#ifndef _DEBUG  // 이유한View.cpp의 디버그 버전
inline C이유한Doc* C이유한View::GetDocument() const
   { return reinterpret_cast<C이유한Doc*>(m_pDocument); }
#endif


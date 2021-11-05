//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>
#include <math.h>

#pragma hdrstop

#include "TClocker.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

#define PI 3.14159265359

static inline void ValidCtrCheck(TClocker*)
{
    new TClocker(NULL);
}
//---------------------------------------------------------------------------
__fastcall TClocker::TClocker(TComponent* Owner)
    : TGraphicControl(Owner)
{
    m_dRadius = 20;
}
//---------------------------------------------------------------------------
namespace Tclocker {
void __fastcall PACKAGE Register()
{
    TComponentClass classes[1] = { __classid(TClocker) };
    RegisterComponents(L"Samples", classes, 0);
}
}

void TClocker::setCurrentTime()
{
    time_t theTime = time(NULL);
    struct tm* aTime = localtime(&theTime);

    m_nHour = aTime->tm_hour;
    m_nMinute = aTime->tm_min;

    Paint();
}

void TClocker::changeTime(int minutes)
{
    // m_nHour
    // m_nMinute

    m_nMinute = minutes;

    if (m_nMinute > 60) {
        while (m_nMinute > 60) {
            setH(m_nHour + 1);
            m_nMinute -= 60;
        }
    }

    Paint();
}

void __fastcall TClocker::Paint(void)
{
    // m_dHourAngle;
    // m_dMinuteAngle;
    //	m_dHourAngle -= 90;
    //	m_dMinuteAngle -= 60;

    // clean
    PatBlt(Canvas->Handle, 0, 0, Width, Height, WHITENESS);

    // draw circle
    Canvas->Pen->Color = clDkGray;
    Canvas->Pen->Width = 2;

    Canvas->Ellipse(0, 0, m_dRadius * 2, m_dRadius * 2);

    // m_dHourAngle;
    // m_dMinuteAngle;

    // draw hour
    double x = m_dRadius + (m_dRadius * cos(m_dHourAngle * PI / 180));
    double y = m_dRadius + (m_dRadius * sin(m_dHourAngle * PI / 180));

    Canvas->Pen->Color = clRed;
    Canvas->Pen->Width = 3;

    Canvas->MoveTo(m_dRadius, m_dRadius);
    Canvas->LineTo(x, y);

    // draw minutes
    x = m_dRadius + (m_dRadius * cos(m_dMinuteAngle * PI / 180));
    y = m_dRadius + (m_dRadius * sin(m_dMinuteAngle * PI / 180));

    Canvas->Pen->Color = clBlue;
    Canvas->Pen->Width = 2;

    Canvas->MoveTo(m_dRadius, m_dRadius);
    Canvas->LineTo(x, y);
}

//---------------------------------------------------------------------------

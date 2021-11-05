//---------------------------------------------------------------------------

#ifndef TClockerH
#define TClockerH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <iostream>
//---------------------------------------------------------------------------
class PACKAGE TClocker : public TGraphicControl {
private:
    double m_dRadius;
    double m_dHourAngle;
    double m_dMinuteAngle;

    unsigned int m_nHour;
    unsigned int m_nMinute;

    bool m_bSetCurTime;

    TNotifyEvent m_fOnDblClick;

protected:
    virtual void __fastcall Paint(void);

public:
    __fastcall TClocker(TComponent* Owner);

    virtual __fastcall void setCurrentTime();
    virtual void changeTime(int);

    virtual __fastcall void setH(unsigned int h)
    {
        m_nHour = h;

        if (m_nHour > 24) {
            while (m_nHour > 24) {
                m_nHour -= 24;
            }
        }

        switch (m_nHour) {
        case 1:
        case 13:
            m_dHourAngle = 300;
            break;

        case 2:
        case 14:
            m_dHourAngle = 330;
            break;
        case 3:
        case 15:
            m_dHourAngle = 360;
            break;
        case 4:
        case 16:
            m_dHourAngle = 30;
            break;
        case 5:
        case 17:
            m_dHourAngle = 60;
            break;
        case 6:
        case 18:
            m_dHourAngle = 90;
            break;
        case 7:
        case 19:
            m_dHourAngle = 120;
            break;
        case 8:
        case 20:
            m_dHourAngle = 150;
            break;
        case 9:
        case 21:
            m_dHourAngle = 180;
            break;
        case 10:
        case 22:
            m_dHourAngle = 210;
            break;
        case 11:
        case 23:
            m_dHourAngle = 240;
            break;
        case 12:
        case 24:
        case 0:
            m_dHourAngle = 270;
            break;
        }

        Paint();
    }
    virtual __fastcall void setM(unsigned int m)
    {
        m_nMinute = m;

        if (m_nMinute > 60) {
            while (m_nMinute > 60) {
                setH(m_nHour + 1);
                m_nMinute -= 60;
            }
        }

        if (m_nMinute == 0) {
            m_dMinuteAngle = 270;
        }
        else {
            m_dMinuteAngle = (6 * m_nMinute);
            m_dMinuteAngle -= 90;
        }

        Paint();
    }

    virtual __fastcall void setHA(double a)
    {
        m_dHourAngle = a;
        Paint();
    }
    virtual __fastcall void setMA(double a)
    {
        m_dMinuteAngle = a;
        Paint();
    }

    virtual __fastcall void setR(double r)
    {
        m_dRadius = r;
        Paint();
    }

    __published : __property OnDblClick;

    __property bool SetCurTime = { read = m_bSetCurTime, write = setCurrentTime };

    __property double Radius = { read = m_dRadius, write = setR };

    __property double HourAngle = { read = m_dHourAngle, write = setHA };
    __property double MinuteAngle = { read = m_dMinuteAngle, write = setMA };

    __property unsigned int Hour = { read = m_nHour, write = setH };
    __property unsigned int Minute = { read = m_nMinute, write = setM };
};
//---------------------------------------------------------------------------
#endif

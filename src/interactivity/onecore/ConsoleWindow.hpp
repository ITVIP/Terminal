/*++
Copyright (c) Microsoft Corporation

Module Name:
- ConsoleWindow.hpp

Abstract:
- OneCore implementation of the IConsoleWindow interface.

Author(s):
- Hernan Gatta (HeGatta) 29-Mar-2017
--*/

#pragma once

#include "..\inc\IConsoleWindow.hpp"

#pragma hdrstop

namespace Microsoft
{
    namespace Console
    {
        namespace Interactivity
        {
            namespace OneCore
            {
                class ConsoleWindow sealed : public IConsoleWindow
                {
                public:

                    // Inherited via IConsoleWindow
                    BOOL EnableBothScrollBars();
                    int UpdateScrollBar(bool isVertical, bool isAltBuffer, UINT pageSize, int maxSize, int viewportPosition);

                    bool IsInFullscreen() const;
                    void SetIsFullscreen(bool const fFullscreenEnabled);
                    NTSTATUS SetViewportOrigin(SMALL_RECT NewWindow);
                    void SetWindowHasMoved(BOOL const fHasMoved);

                    void CaptureMouse();
                    BOOL ReleaseMouse();

                    HWND GetWindowHandle() const;

                    void SetOwner();

                    BOOL GetCursorPosition(LPPOINT lpPoint);
                    BOOL GetClientRectangle(LPRECT lpRect);
                    int MapPoints(LPPOINT lpPoints, UINT cPoints);
                    BOOL ConvertScreenToClient(LPPOINT lpPoint);

                    BOOL SendNotifyBeep() const;

                    BOOL PostUpdateScrollBars() const;
                    BOOL PostUpdateTitleWithCopy(const PCWSTR pwszNewTitle) const;
                    BOOL PostUpdateWindowSize() const;

                    void UpdateWindowSize(COORD const coordSizeInChars) const;
                    void UpdateWindowText();

                    void HorizontalScroll(const WORD wScrollCommand, const WORD wAbsoluteChange) const;
                    void VerticalScroll(const WORD wScrollCommand, const WORD wAbsoluteChange) const;

                    HRESULT SignalUia(_In_ EVENTID id);
                    RECT GetWindowRect() const;
                };
            };
        };
    };
};
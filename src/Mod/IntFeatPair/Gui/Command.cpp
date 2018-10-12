/***************************************************************************
 *   Copyright (c) YEAR YOUR NAME         <Your e-mail address>            *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"
#ifndef _PreComp_
#endif

#include <Base/Console.h>
#include <App/Document.h>
#include <Gui/Application.h>
#include <Gui/Command.h>


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//===========================================================================
// CmdIntFeatPairTest THIS IS JUST A TEST COMMAND
//===========================================================================
DEF_STD_CMD(CmdIntFeatPairTest)

CmdIntFeatPairTest::CmdIntFeatPairTest()
  :Command("IntFeatPair_Test")
{
    sAppModule    = "IntFeatPair";
    sGroup        = QT_TR_NOOP("IntFeatPair");
    sMenuText     = QT_TR_NOOP("Hello");
    sToolTipText  = QT_TR_NOOP("IntFeatPair Test function");
    sWhatsThis    = "IntFeatPair_Test";
    sStatusTip    = QT_TR_NOOP("IntFeatPair Test function");
    sPixmap       = "Test1";
    sAccel        = "CTRL+H";
}

void CmdIntFeatPairTest::activated(int)
{
    Base::Console().Message("Hello, World!\n");
}

void CreateIntFeatPairCommands(void)
{
    Gui::CommandManager &rcCmdMgr = Gui::Application::Instance->commandManager();
    rcCmdMgr.addCommand(new CmdIntFeatPairTest());
}

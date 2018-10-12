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
# include <qobject.h>
# include <boost/bind.hpp>
#endif

#include "Workbench.h"
#include <Gui/MenuManager.h>
#include <Gui/ToolBarManager.h>

using namespace IntFeatPairGui;

/// @namespace IntFeatPairGui @class Workbench
TYPESYSTEM_SOURCE(IntFeatPairGui::Workbench, Gui::StdWorkbench)

Workbench::Workbench()
{
}

Workbench::~Workbench()
{
}

Gui::MenuItem* Workbench::setupMenuBar() const
{
    Gui::MenuItem* root = StdWorkbench::setupMenuBar();
    Gui::MenuItem* item = root->findItem( "&Windows" );

    Gui::MenuItem* test = new Gui::MenuItem;
    root->insertItem( item, test );
    test->setCommand("IntFeatPair");
    *test << "IntFeatPair_Test";

    return root;
}

Gui::ToolBarItem* Workbench::setupToolBars() const
{
    Gui::ToolBarItem* root = StdWorkbench::setupToolBars();

    Gui::ToolBarItem* test = new Gui::ToolBarItem(root);
    test->setCommand( "IntFeatPair Tools" );
    *test << "IntFeatPair_Test"; 

    return root;
}

Gui::ToolBarItem* Workbench::setupCommandBars() const
{
	// Part tools
	Gui::ToolBarItem* root = new Gui::ToolBarItem;
	return root;
}


void Workbench::activated()
{
	Gui::Workbench::activated();

	// Let us be notified when a document is activated, so that we can update the ActivePartObject
	Gui::Application::Instance->signalActiveDocument.connect(boost::bind(&Workbench::slotActiveDocument, this, _1));
	App::GetApplication().signalNewDocument.connect(boost::bind(&Workbench::slotNewDocument, this, _1));
	App::GetApplication().signalFinishRestoreDocument.connect(boost::bind(&Workbench::slotFinishRestoreDocument, this, _1));
	App::GetApplication().signalDeleteDocument.connect(boost::bind(&Workbench::slotDeleteDocument, this, _1));
}

void Workbench::deactivated()
{
	// Disconnect all document signals...
	Gui::Application::Instance->signalActiveDocument.disconnect(boost::bind(&Workbench::slotActiveDocument, this, _1));
	App::GetApplication().signalNewDocument.disconnect(boost::bind(&Workbench::slotNewDocument, this, _1));
	App::GetApplication().signalFinishRestoreDocument.disconnect(boost::bind(&Workbench::slotFinishRestoreDocument, this, _1));
	App::GetApplication().signalDeleteDocument.disconnect(boost::bind(&Workbench::slotDeleteDocument, this, _1));

	Gui::Workbench::deactivated();
}

void Workbench::slotActiveDocument(const Gui::Document& Doc)
{
	
}

void Workbench::slotNewDocument(const App::Document& Doc)
{
	
}

void Workbench::slotFinishRestoreDocument(const App::Document& Doc)
{
	
}

void Workbench::slotDeleteDocument(const App::Document&)
{
	
}

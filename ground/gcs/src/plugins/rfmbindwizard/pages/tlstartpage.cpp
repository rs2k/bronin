/**
 ******************************************************************************
 *
 * @file       startpage.cpp
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2014
 * @see        The GNU Public License (GPL) Version 3
 *
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup RfmBindWizard Setup Wizard
 * @{
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */
#include "tlstartpage.h"
#include "ui_startpage.h"

TLStartPage::TLStartPage(RfmBindWizard *wizard, QWidget *parent)
    : AbstractWizardPage(wizard, parent)
    , ui(new Ui::StartPage)
{
    ui->setupUi(this);
    setFont(QFont("Ubuntu", 2));
}

TLStartPage::~TLStartPage()
{
    delete ui;
}

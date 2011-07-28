/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkSearchBox_h
#define __ctkSearchBox_h

// QT includes
#include <QLineEdit>

// CTK includes
#include "ctkWidgetsExport.h"

class ctkSearchBoxPrivate;

/// QLineEdit with two QIcons on each side: search and clear.
/// "Search" selects all the text
/// "Clear" clears the current text
/// See QLineEdit::text to set/get the current text.
/// ctkSearchBox's purpose is to be used to filter other widgets.
/// e.g.:
/// <code>
///  ctkSearchBox searchBox;
///  QSortFilterProxyModel filterModel;
///  QObject::connect(&searchBox, SIGNAL(textChanged(QString)),
///                   &filterModel, SLOT(setFilterFixedString(QString)));
///  ...
/// </code>
class CTK_WIDGETS_EXPORT ctkSearchBox : public QLineEdit
{
  Q_OBJECT

public:
  /// Superclass typedef
  typedef QLineEdit Superclass;

  ctkSearchBox(QWidget *parent = 0);
  virtual ~ctkSearchBox();

protected slots:
  /// Change the clear icon's state to enabled or disabled.
  void updateClearButtonState();

protected:
  virtual void paintEvent(QPaintEvent*);
  virtual void mousePressEvent(QMouseEvent* event);
  virtual void mouseMoveEvent(QMouseEvent *event);
  virtual void resizeEvent(QResizeEvent * event);

  QScopedPointer<ctkSearchBoxPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(ctkSearchBox);
  Q_DISABLE_COPY(ctkSearchBox);
};
#endif // __ctkSearchBox_h


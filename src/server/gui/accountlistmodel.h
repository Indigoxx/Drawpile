/*
   Drawpile - a collaborative drawing program.

   Copyright (C) 2017 Calle Laakkonen

   Drawpile is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Drawpile is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Drawpile.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ACCOUNTLISTMODEL_H
#define ACCOUNTLISTMODEL_H

#include <QAbstractTableModel>
#include <QJsonArray>

namespace server {
namespace gui {

class AccountListModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit AccountListModel(QObject *parent=nullptr);

	void setAccountList(const QJsonArray &accounts);
	void addAccount(const QJsonObject &entry);
	void updateAccount(const QJsonObject &entry);
	void removeAccount(int id);

	QJsonObject accountAt(int row) const;

	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent=QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
	QJsonArray m_accountlist;
};

}
}

#endif

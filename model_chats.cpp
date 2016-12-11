#include "model_chats.h"

Model_Chats::Model_Chats(QObject *parent)
	: QAbstractListModel(parent)
{

	cout << "moel_char create\n";
}

QVariant Model_Chats::headerData(int section, Qt::Orientation orientation, int role) const
{
	// FIXME: Implement me!
}

bool Model_Chats::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
	if (value != headerData(section, orientation, role)) {
		// FIXME: Implement me!
		emit headerDataChanged(orientation, section, section);
		return true;
	}
	return false;
}

int Model_Chats::rowCount(const QModelIndex &parent) const
{
	// For list models only the root node (an invalid parent) should return the list's size. For all
	// other (valid) parents, rowCount() should return 0 so that it does not become a tree model.

	return client->room.size();
	// FIXME: Implement me!
}

QVariant Model_Chats::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	switch(role){
	case Qt::DisplayRole:
		list<Chat>::iterator iter = client->room.begin();
		advance(iter, index.row());
		//Chat chat = *iter;
		return QVariant(QString::fromStdString(iter->get_companion_name()));
	}
	// FIXME: Implement me!
	return QVariant();
}

bool Model_Chats::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (data(index, role) != value) {
		// FIXME: Implement me!
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}
	return false;
}

Qt::ItemFlags Model_Chats::flags(const QModelIndex &index) const
{
//	if (!index.isValid())
//		return Qt::NoItemFlags;

	return Qt::ItemIsEditable | Qt::ItemIsSelectable; // FIXME: Implement me!
}

bool Model_Chats::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row + count - 1);
	// FIXME: Implement me!
	endInsertRows();
}

bool Model_Chats::removeRows(int row, int count, const QModelIndex &parent)
{
	beginRemoveRows(parent, row, row + count - 1);
	// FIXME: Implement me!
	endRemoveRows();
}

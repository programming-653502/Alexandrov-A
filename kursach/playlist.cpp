#include "playlist.h"

#include <QFileInfo>
#include <QUrl>
#include <QMediaPlaylist>



void ListModel::endInrtIs()
{
    endInsertRows();
}

void ListModel::beginRemoveItems(int start, int end)
{
    m_data.clear();
    beginRemoveRows(QModelIndex(), start, end);
}

void ListModel::endRemoveItems()
{
    endInsertRows();
}

int ListModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? ColumnCount : 0;
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return myfirst_playlist && !parent.isValid() ? myfirst_playlist->mediaCount() : 0;
}

void ListModel::setPlaylist(QMediaPlaylist *playlist)
{
    if (myfirst_playlist) {
        disconnect(myfirst_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(bgnInsert(int,int)));
        disconnect(myfirst_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInrtIs()));
        disconnect(myfirst_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        disconnect(myfirst_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        disconnect(myfirst_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }

    beginResetModel();
    myfirst_playlist = playlist;

    if (myfirst_playlist) {
        connect(myfirst_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(bgnInsert(int,int)));
        connect(myfirst_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInrtIs()));
        connect(myfirst_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        connect(myfirst_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        connect(myfirst_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }

    endResetModel();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        QVariant value = m_data[index];
        if (!value.isValid() && index.column() == Title) {
            QUrl location = myfirst_playlist->media(index.row()).canonicalUrl();
            return QFileInfo(location.path()).fileName();
        }

        return value;
    }
    return QVariant();
}


QModelIndex ListModel::index(int row, int column, const QModelIndex &parent) const
{
    return myfirst_playlist && !parent.isValid()
            && row >= 0 && row < myfirst_playlist->mediaCount()
            && column >= 0 && column < ColumnCount
        ? createIndex(row, column)
        : QModelIndex();
}

QModelIndex ListModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);

    return QModelIndex();
}


QMediaPlaylist *ListModel::playlist() const
{
    return myfirst_playlist;
}

ListModel::ListModel(QObject *parent)
    : QAbstractItemModel(parent)
    , myfirst_playlist(0)
{
}



bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    m_data[index] = value;
    emit dataChanged(index, index);
    return true;
}

void ListModel::bgnInsert(int start, int end)
{
    m_data.clear();
    beginInsertRows(QModelIndex(), start, end);
}



void ListModel::changeItems(int start, int end)
{
    m_data.clear();
    emit dataChanged(index(start,0), index(end,ColumnCount));
}

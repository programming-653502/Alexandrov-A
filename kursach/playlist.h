#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QAbstractItemModel>

QT_BEGIN_NAMESPACE
class QMediaPlaylist;
QT_END_NAMESPACE

class ListModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QMediaPlaylist *playlist() const;
    void setPlaylist(QMediaPlaylist *playlist);

    enum Column
    {
        Title = 0,
        ColumnCount
    };

    ListModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;


    bool setData(const QModelIndex &index, const QVariant &value, int correctrole = Qt::DisplayRole);

private slots:
    void bgnInsert(int begin, int end);
    void endInrtIs();
    void beginRemoveItems(int begin, int end);
    void endRemoveItems();
    void changeItems(int begin, int end);

private:
    QMediaPlaylist *myfirst_playlist;
    QMap<QModelIndex, QVariant> m_data;
};

#endif

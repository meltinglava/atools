/*****************************************************************************
* Copyright 2015-2018 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef ATOOLS_HTTPDOWNLOADER_H
#define ATOOLS_HTTPDOWNLOADER_H

#include <QNetworkAccessManager>
#include <QObject>
#include <QTimer>

class QNetworkReply;

namespace atools {
namespace util {

/*
 * Simple async HTTP download tool that reads files from web addresses.
 * Has a timer to do recurring downloads.
 */
class HttpDownloader :
  public QObject
{
  Q_OBJECT

public:
  HttpDownloader(QObject *parent, bool logVerbose = false);
  virtual ~HttpDownloader();

  /* Download file and emit downloadFinished when done.
   * Will start update timer after download if period <> -1.
   * Cancels all previous downloads. */
  void startDownload();
  void cancelDownload();

  /* Set download request URL */
  void setUrl(const QString& requestUrl)
  {
    url = requestUrl;
  }

  const QString& getUrl() const
  {
    return url;
  }

  /* Re-download every number of seconds and emit downloadFinished when done. */
  void setUpdatePeriod(int seconds);

  void startTimer();
  void stopTimer();

  /* Is valid until next startDownload call */
  const QByteArray& getData() const
  {
    return data;
  }

  const QString& getUserAgent() const
  {
    return userAgent;
  }

  void setUserAgent(const QString& value)
  {
    userAgent = value;
  }

signals:
  /* Emitted when file was downloaded and udpated */
  void downloadFinished(const QByteArray& data, QString url);
  void downloadFailed(const QString& error, QString url);
  void downloadProgress(qint64 bytesReceived, qint64 bytesTotal, QString url);

private:
  /* Request completely finished */
  void httpFinished();

  /* Cancel request and free resources */
  void deleteReply();

  /* A chunk of data is available */
  void readyRead();

  void downloadProgressInternal(qint64 bytesReceived, qint64 bytesTotal);

  QNetworkAccessManager networkManager;
  QTimer updateTimer;
  QString url, userAgent;
  int updatePeriodSeconds = -1;
  QNetworkReply *reply = nullptr;
  QByteArray data;
  bool verbose;
};

} // namespace util
} // namespace atools

#endif // ATOOLS_HTTPDOWNLOADER_H
#include <QGuiApplication>
#include <QProcess>
#include <QQmlApplicationEngine>

class ProcessStarter : public QProcess {
  Q_OBJECT

public:
  ProcessStarter(QObject *parent = 0) : QProcess(parent) {}
  virtual ~ProcessStarter() = default;

  Q_INVOKABLE void changeTime(const qint32 time) {
    QStringList args;

    currentTime += time;

    if (currentTime < 0) {
      currentTime = 0;
    }

    QString channel = "prima_cool";
    QString quality = "hq";

    QMap<QString, QString> id_map;
    id_map["prima_family"] = "id-p111013";
    id_map["prima_cool"] = "id-p111014";
    id_map["prima_zoom"] = "id-p111015";
    id_map["prima_love"] = "id-p111016";
    id_map["prima_max"] = "id-p111017";
    id_map["prima_krimi"] = "id-p432829";
    id_map["prima_star"] = "id-p846043";
    id_map["prima_show"] = "id-p899572";

    QString api_url = "https://api.play-backend.iprima.cz/api/v1/products/" +
                      id_map[channel] + "/play";

    QMap<QString, QString> cookie_map;

    cookie_map["prima_family"] = "OdgM1iCkqWOqr5BWPbiozA==,1652124704";
    cookie_map["prima_cool"] = "gr6hcL9RWmVgjLeMoIeOnw==,1652114961";
    cookie_map["prima_max"] = "RtNXiWVakNRqIhtwk2wizA==,1652125182";

    QString url = "https://prima-ott-live-sec.ssl.cdn.cra.cz/" +
                  cookie_map[channel] + "/channels/" + channel +
                  "/"
                  "playlist/cze/live_" +
                  quality +
                  ".m3u8?offsetSeconds=" + QString::number(currentTime) +
                  "&url=0";

    args << url;

    if (state() == 2) {
      kill();
      waitForFinished();
    }

    QProcess::start("mpv", args);
  }
  qint32 currentTime = 0;
};

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);

  qmlRegisterType<ProcessStarter>("Process", 1, 0, "ProcessStarter");

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}

#include "main.moc"

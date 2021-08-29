#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QTextEdit>
#include <QTimer>
#include <QApplication>
#include <QStandardPaths>
#include <QTest>

#include <kxmlguiwindow.h>
#include <kactioncollection.h>
#include <kmessagebox.h>
#include <kconfiggroup.h>
class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public Q_SLOTS:
    void slotTest();
    void slotCreate();

private:
    void setupActions();
};
#endif // MAINWINDOW_H

//Windows系统下
//DesktopLocation:   	  C:/Users/<USER>/Desktop
//DocumentsLocation:         C:/Users/<USER>/Documents
//FontsLocation:                    C:/Windows/Fonts  (不可写)
//ApplicationsLocation:       C:/Users/<USER>/AppData/Roaming/Microsoft/Windows/Start Menu/Programs
//MusicLocation:          C:/Users/<USER>/Music
//MoviesLocation:       C:/Users/<USER>/Videos
//PicturesLocation:      C:/Users/<USER>/Pictures
//TempLocation:                    C:/Users/<USER>/AppData/Local/Temp
//HomeLocation:          C:/Users/<USER>
//DataLocation:           C:/Users/<USER>/AppData/Local/<APPNAME> ,  C:/ProgramData/<APPNAME> ,  <APPDIR> ,  <APPDIR>/data ,  <APPDIR>/data/<APPNAME>
//CacheLocation:         C:/Users/<USER>/AppData/Local/<APPNAME>/cache
//GenericDataLocation:      C:/Users/<USER>/AppData/Local ,  C:/ProgramData ,  <APPDIR> ,  <APPDIR>/data
//RuntimeLocation:     C:/Users/<USER>
//ConfigLocation:         C:/Users/<USER>/AppData/Local/<APPNAME> ,  C:/ProgramData/<APPNAME>
//GenericConfigLocation:    C:/Users/<USER>/AppData/Local ,  C:/ProgramData
//DownloadLocation:           C:/Users/<USER>/Documents
//GenericCacheLocation:    C:/Users/<USER>/AppData/Local/cache
//AppDataLocation:    C:/Users/<USER>/AppData/Roaming/<APPNAME> ,  C:/ProgramData/<APPNAME> ,  <APPDIR> ,  <APPDIR>/data ,  <APPDIR>/data/<APPNAME>
//AppLocalDataLocation:    C:/Users/<USER>/AppData/Local/<APPNAME> ,  C:/ProgramData/<APPNAME> ,  <APPDIR> ,  <APPDIR>/data ,  <APPDIR>/data/<APPNAME>
//AppConfigLocation:           C:/Users/<USER>/AppData/Local/<APPNAME> ,  C:/ProgramData/<APPNAME> </code></pre>

//Linux系统下
//DesktopLocation:     ~/Desktop
//DocumentsLocation:         ~/Documents
//FontsLocation:                    ~/.fonts ,  ~/.local/share/fonts ,  /usr/local/share/fonts ,  /usr/share/fonts
//ApplicationsLocation:       ~/.local/share/applications ,  /usr/local/share/applications ,  /usr/share/applications
//MusicLocation:          ~/Music
//MoviesLocation:       ~/Videos
//PicturesLocation:      ~/Pictures
//TempLocation:                    /tmp
//HomeLocation:          ~
//DataLocation:           ~/.local/share/<APPNAME> ,  /usr/local/share/<APPNAME> ,  /usr/share/<APPNAME>
//CacheLocation:         ~/.cache/<APPNAME>
//GenericDataLocation:      ~/.local/share ,  /usr/local/share ,  /usr/share
//RuntimeLocation:     /run/user/<USER>
//ConfigLocation:         ~/.config ,  /etc/xdg
//GenericConfigLocation:    ~/.config ,  /etc/xdg
//DownloadLocation:           ~/Downloads
//GenericCacheLocation:    ~/.cache
//AppDataLocation:    ~/.local/share/<APPNAME> ,  /usr/local/share/<APPNAME> ,  /usr/share/<APPNAME>
//AppLocalDataLocation:    ~/.local/share/<APPNAME> ,  /usr/local/share/<APPNAME> ,  /usr/share/<APPNAME>
//AppConfigLocation:          ~/.config/<APPNAME> ,  /etc/xdg/<APPNAME> </code></pre>

//macOS系统下
//DesktopLocation:     ~/Desktop
//DocumentsLocation:         ~/Documents
//FontsLocation:           /System/Library/Fonts  (不可写入)
//ApplicationsLocation:       /Applications  (不可写入)
//MusicLocation:          ~/Music
//MoviesLocation:       ~/Movies
//PicturesLocation:      ~/Pictures
//TempLocation:          由系统随机生成
//HomeLocation:          ~
//DataLocation:            ~/Library/Application Support/<APPNAME> ,  /Library/Application Support/<APPNAME> .  <APPDIR>/../Resources
//CacheLocation:         ~/Library/Caches/<APPNAME> ,  /Library/Caches/<APPNAME>
//GenericDataLocation:      ~/Library/Application Support ,  /Library/Application Support
//RuntimeLocation:     ~/Library/Application Support
//ConfigLocation:         ~/Library/Preferences
//GenericConfigLocation:    ~/Library/Preferences
//DownloadLocation:  ~/Downloads
//GenericCacheLocation:    ~/Library/Caches ,  /Library/Caches
//AppDataLocation:    ~/Library/Application Support/<APPNAME> ,  /Library/Application Support/<APPNAME> .  <APPDIR>/../Resources
//AppLocalDataLocation:    ~/Library/Application Support/<APPNAME> ,  /Library/Application Support/<APPNAME> .  <APPDIR>/../Resources
//AppConfigLocation: ~/Library/Preferences/<APPNAME> </code></pre>

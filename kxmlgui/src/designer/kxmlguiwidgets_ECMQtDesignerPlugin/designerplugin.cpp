// DO NOT EDIT! Generated from ecm_add_qtdesignerplugin()

#include <QDesignerCustomWidgetCollectionInterface>
#include <QDesignerCustomWidgetInterface>
#include <QObject>
#include <QIcon>
#include <QString>
#include <kkeysequencewidget.h>
#include <kshortcutseditor.h>
#include <kshortcutwidget.h>

class KKeySequenceWidgetQtDesignerWidgetFactory
    : public QObject
    , public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    explicit KKeySequenceWidgetQtDesignerWidgetFactory(QObject *parent = nullptr)
        : QObject(parent)
        , m_initialized(false)
    {}

    ~KKeySequenceWidgetQtDesignerWidgetFactory() override {}
    
public: // QDesignerCustomWidgetInterface API
    bool isInitialized() const override { return m_initialized; }

    bool isContainer() const override { return false; }
    QIcon icon() const override { return QIcon(); }
    QString group() const override { return QStringLiteral("Buttons (KF5)"); }
    QString includeFile() const override { return QStringLiteral("kkeysequencewidget.h"); }
    QString name() const override { return QStringLiteral("KKeySequenceWidget"); }
    QString toolTip() const override { return QStringLiteral("QKeySequence picker widget. (KF5)"); }
    QString whatsThis() const override { return QStringLiteral("A widget to pick a QKeySequence."); }

    QWidget* createWidget(QWidget* parent) override
    {
        return new KKeySequenceWidget(parent);
    }

    void initialize(QDesignerFormEditorInterface* core) override 
    {
        Q_UNUSED(core);

        if (m_initialized) return;

        m_initialized = true;
    }

private:
    bool m_initialized;
};

class KShortcutsEditorQtDesignerWidgetFactory
    : public QObject
    , public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    explicit KShortcutsEditorQtDesignerWidgetFactory(QObject *parent = nullptr)
        : QObject(parent)
        , m_initialized(false)
    {}

    ~KShortcutsEditorQtDesignerWidgetFactory() override {}
    
public: // QDesignerCustomWidgetInterface API
    bool isInitialized() const override { return m_initialized; }

    bool isContainer() const override { return false; }
    QIcon icon() const override { return QIcon(); }
    QString group() const override { return QStringLiteral("Input (KF5)"); }
    QString includeFile() const override { return QStringLiteral("kshortcutseditor.h"); }
    QString name() const override { return QStringLiteral("KShortcutsEditor"); }
    QString toolTip() const override { return QStringLiteral("Shortcuts editor widget. (KF5)"); }
    QString whatsThis() const override { return QStringLiteral("A widget to edit a list of shortcuts."); }

    QWidget* createWidget(QWidget* parent) override
    {
        return new KShortcutsEditor(parent);
    }

    void initialize(QDesignerFormEditorInterface* core) override 
    {
        Q_UNUSED(core);

        if (m_initialized) return;

        m_initialized = true;
    }

private:
    bool m_initialized;
};

class KShortcutWidgetQtDesignerWidgetFactory
    : public QObject
    , public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    explicit KShortcutWidgetQtDesignerWidgetFactory(QObject *parent = nullptr)
        : QObject(parent)
        , m_initialized(false)
    {}

    ~KShortcutWidgetQtDesignerWidgetFactory() override {}
    
public: // QDesignerCustomWidgetInterface API
    bool isInitialized() const override { return m_initialized; }

    bool isContainer() const override { return false; }
    QIcon icon() const override { return QIcon(); }
    QString group() const override { return QStringLiteral("Buttons (KF5)"); }
    QString includeFile() const override { return QStringLiteral("kshortcutwidget.h"); }
    QString name() const override { return QStringLiteral("KShortcutWidget"); }
    QString toolTip() const override { return QStringLiteral("Shortcut picker widget. (KF5)"); }
    QString whatsThis() const override { return QStringLiteral("A widget to pick a KShortcut."); }

    QWidget* createWidget(QWidget* parent) override
    {
        return new KShortcutWidget(parent);
    }

    void initialize(QDesignerFormEditorInterface* core) override 
    {
        Q_UNUSED(core);

        if (m_initialized) return;

        m_initialized = true;
    }

private:
    bool m_initialized;
};

class KXmlGuiWidgetsQtDesignerWidgetCollection
    : public QObject
    , public QDesignerCustomWidgetCollectionInterface
{
    Q_OBJECT
    Q_INTERFACES(
        QDesignerCustomWidgetCollectionInterface
    )

    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")

public:
    explicit KXmlGuiWidgetsQtDesignerWidgetCollection(QObject* parent = nullptr);

public: // QDesignerCustomWidgetCollectionInterface API
    QList<QDesignerCustomWidgetInterface*> customWidgets() const override;

private:
    QList<QDesignerCustomWidgetInterface*> m_widgetFactories;
};

KXmlGuiWidgetsQtDesignerWidgetCollection::KXmlGuiWidgetsQtDesignerWidgetCollection(QObject* parent)
    : QObject(parent)
{
    m_widgetFactories = QList<QDesignerCustomWidgetInterface*>{
        new KKeySequenceWidgetQtDesignerWidgetFactory(this),
        new KShortcutsEditorQtDesignerWidgetFactory(this),
        new KShortcutWidgetQtDesignerWidgetFactory(this),
    };
}

QList<QDesignerCustomWidgetInterface*> KXmlGuiWidgetsQtDesignerWidgetCollection::customWidgets() const
{
    return m_widgetFactories;
}

#include "designerplugin.moc"

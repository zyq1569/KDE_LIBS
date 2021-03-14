#ifndef CLOSEDIALOGHELPER_H
#define CLOSEDIALOGHELPER_H

#include <QDialogButtonBox>
#include <QObject>

#include "../part/part.h"

#define KDESRCDIR "./autotests/"

namespace TestingUtils
{
/*
 *  The CloseDialogHelper class is a helper to auto close modals opened in tests.
 */
class CloseDialogHelper : public QObject
{
    Q_OBJECT

public:
    CloseDialogHelper(Okular::Part *p, QDialogButtonBox::StandardButton b);

    CloseDialogHelper(QWidget *w, QDialogButtonBox::StandardButton b);

    // Close a modal dialog, which may not be associated to any other widget
    CloseDialogHelper(QDialogButtonBox::StandardButton b);

    ~CloseDialogHelper() override;

private slots:
    void closeDialog();

private:
    QWidget *m_widget;
    QDialogButtonBox::StandardButton m_button;
    bool m_clicked;
};

}

namespace Okular
{
class PartTest : public QObject
{
    Q_OBJECT

    static bool openDocument(Okular::Part *part, const QString &filePath);

signals:
    void urlHandler(const QUrl &url); // NOLINT(readability-inconsistent-declaration-parameter-name)

private slots:
    void testReload();
    void testCanceledReload();
    void testTOCReload();
    void testForwardPDF();
    void testForwardPDF_data();
    void testGeneratorPreferences();
    void testSelectText();
    void testClickInternalLink();
    void testScrollBarAndMouseWheel();
    void testOpenUrlArguments();
    void test388288();
    void testSaveAs();
    void testSaveAs_data();
    void testSaveAsToNonExistingPath();
    void testSaveAsToSymlink();
    void testSaveIsSymlink();
    void testSidebarItemAfterSaving();
    void testViewModeSavingPerFile();
    void testSaveAsUndoStackAnnotations();
    void testSaveAsUndoStackAnnotations_data();
    void testSaveAsUndoStackForms();
    void testSaveAsUndoStackForms_data();
    void testMouseMoveOverLinkWhileInSelectionMode();
    void testClickUrlLinkWhileInSelectionMode();
    void testeTextSelectionOverAndAcrossLinks_data();
    void testeTextSelectionOverAndAcrossLinks();
    void testClickUrlLinkWhileLinkTextIsSelected();
    void testRClickWhileLinkTextIsSelected();
    void testRClickOverLinkWhileLinkTextIsSelected();
    void testRClickOnSelectionModeShoulShowFollowTheLinkMenu();
    void testClickAnywhereAfterSelectionShouldUnselect();
    void testeRectSelectionStartingOnLinks();
    void testCheckBoxReadOnly();
    void testCrashTextEditDestroy();
    void testAnnotWindow();
    void testAdditionalActionTriggers();
    void testTypewriterAnnotTool();
    void testJumpToPage();
    void testOpenAtPage();
    void testForwardBackwardNavigation();
    void testTabletProximityBehavior();
    void testOpenPrintPreview();
    void testMouseModeMenu();
    void testFullScreenRequest();
    void testZoomInFacingPages();

private:
    void simulateMouseSelection(double startX, double startY, double endX, double endY, QWidget *target);
};
}
#endif // CLOSEDIALOGHELPER_H

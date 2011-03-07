#ifndef LIVEVIEWWINDOW_H
#define LIVEVIEWWINDOW_H

#include <QWidget>
#include "core/DVRCamera.h"

class LiveViewArea;
class QComboBox;

class LiveViewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LiveViewWindow(QWidget *parent = 0);

    /* Note that the returned window has the Qt::WA_DeleteOnClose attribute set.
     * If you intend to save this pointer long-term, put it in a guard (QWeakPointer) or
     * unset this attribute. */
    static LiveViewWindow *openWindow(QWidget *parent, const DVRCamera &camera = DVRCamera());

    LiveViewArea *view() const { return m_liveView; }

    void setAutoSized(bool autoSized);

public slots:
    void showSingleCamera(const DVRCamera &camera);
    void saveLayout();

private slots:
    void savedLayoutChanged(int index);
    void showLayoutMenu(const QPoint &pos, int index = -1);
    void doAutoResize();

private:
    LiveViewArea * const m_liveView;
    QComboBox * const m_savedLayouts;
    int m_lastLayoutIndex;
    bool m_autoSized;
};

#endif // LIVEVIEWWINDOW_H
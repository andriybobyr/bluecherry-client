#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H

#include <QWidget>

class DVRServersView;
class EventsView;
class EventTimelineWidget;
class EventTypesFilter;
class EventTagsView;
class QLabel;
class QBoxLayout;
class QDateEdit;
class QComboBox;
class QSlider;
class QModelIndex;
class QDateTime;

class EventsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EventsWindow(QWidget *parent = 0);
    ~EventsWindow();

    static EventsWindow *instance();

protected:
    virtual void closeEvent(QCloseEvent *event);

private slots:
    void setStartDateEnabled(bool enabled);
    void setEndDateEnabled(bool enabled);
    void setEndDateMinimum(const QDateTime &date);
    void levelFilterChanged();
    void updateResultTitle();

    void timelineZoomChanged(int value);
    void timelineZoomRangeChanged(int min, int max);
    void timelineSliderChanged(int value);

    void showEvent(const QModelIndex &index);

private:
    static EventsWindow *m_instance;

    DVRServersView *m_sourcesView;
    QDateEdit *m_startDate, *m_endDate;
    QComboBox *m_levelFilter;
    EventTypesFilter *m_typeFilter;
    EventTagsView *m_tagsView;
    QLabel *m_resultTitle;
    EventsView *m_resultsView;
    EventTimelineWidget *m_timeline;
    QSlider *m_timelineZoom;

    void createDateFilter(QBoxLayout *layout);
    QWidget *createLevelFilter();
    QWidget *createTypeFilter();
    QWidget *createTags();
    QWidget *createTagsInput();

    QWidget *createResultTitle();
    QWidget *createResultsView();
    QWidget *createTimeline();
};

#endif // EVENTSWINDOW_H

#ifndef HEATMAP_H
#define HEATMAP_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <vector>

namespace Ui {
class HeatMap;
}

class HeatMap : public QDialog
{
    Q_OBJECT

public:
    explicit HeatMap(QWidget *parent = nullptr);
    ~HeatMap();

    void setClickData(const std::vector<int>& clickDistrict);

private:
    Ui::HeatMap *ui;

    QChart* chart;
    QChartView* chartView;
    QScatterSeries* scatterSeries;
    QValueAxis* xAxis;
    QValueAxis* yAxis;
};

#endif // HEATMAP_H

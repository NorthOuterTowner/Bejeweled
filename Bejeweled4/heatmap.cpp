#include "heatmap.h"
#include "ui_heatmap.h"

#include <QtCharts/QChart>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QColor>

HeatMap::HeatMap(QWidget *parent)
    : QDialog(parent), ui(new Ui::HeatMap),
    chart(new QChart()), scatterSeries(new QScatterSeries()),
    xAxis(new QValueAxis()), yAxis(new QValueAxis())
{
    ui->setupUi(this);

    // 初始化图表
    chart->addSeries(scatterSeries);

    // 设置坐标轴范围
    xAxis->setRange(0, 2); // X 轴从 0 到 2
    yAxis->setRange(0, 2); // Y 轴从 0 到 2
    xAxis->setTitleText("X");
    yAxis->setTitleText("Y");

    // 将坐标轴添加到图表中
    chart->setAxisX(xAxis, scatterSeries);
    chart->setAxisY(yAxis, scatterSeries);

    chart->setTitle("点击频次热力图");
    chart->legend()->hide();

    // 创建图表视图并嵌入到 UI
    chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 将 chartView 添加到 UI 布局中
    ui->verticalLayout->addWidget(chartView);
}

HeatMap::~HeatMap()
{
    delete ui;
}

void HeatMap::setClickData(const std::vector<int>& clickDistrict)
{
    if (clickDistrict.size() != 4) return;

    scatterSeries->clear();

    // 定义点的位置和点击频次
    struct Point {
        double x, y;
        int value;
    };

    std::vector<Point> points = {
        {0.5, 1.5, clickDistrict[0]}, // 左上
        {1.5, 1.5, clickDistrict[1]}, // 右上
        {0.5, 0.5, clickDistrict[2]}, // 左下
        {1.5, 0.5, clickDistrict[3]}  // 右下
    };

    // 添加点到散点系列，并为每个点设置颜色
    for (const auto& point : points) {
        scatterSeries->append(point.x, point.y);

        // 使用 HSV 色彩模型设置颜色（频次越高，颜色越红）
        QColor color = QColor::fromHsvF(0.0, point.value / 100.0, 1.0);
        QScatterSeries* singlePointSeries = new QScatterSeries();
        singlePointSeries->append(point.x, point.y);
        singlePointSeries->setColor(color);
        singlePointSeries->setMarkerSize(20); // 调整点大小
        chart->addSeries(singlePointSeries);

        // 使用共享的坐标轴
        singlePointSeries->attachAxis(xAxis);
        singlePointSeries->attachAxis(yAxis);
    }
}

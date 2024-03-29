#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    enum ShapeType {
        Astroid,
        Cycloid,
        HuygensCycloid,
        HypoCycloid,
        FutureCurve
    };

    // background color
    void setBackgroundColor(QColor color) {mBackgroundColor=color;}
    QColor backgroungColor () const {return mBackgroundColor;}

    // shapes
    void setShape(ShapeType shape){mShape = shape; on_shape_changed();}
    ShapeType shape () const {return mShape;}
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:
private:
    void on_shape_changed();
    QPointF compute(float t);
    QPointF compute_astroid (float t);
    QPointF compute_cycloid (float t);
    QPointF compute_huygens (float t);
    QPointF compute_hypo (float t);
    QPointF compute_future_curve (float t);
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    float mIntervalLength;
    float mScale;
    int mStepCount;
};

#endif // RENDERAREA_H

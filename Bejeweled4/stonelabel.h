#ifndef STONELABEL_H
#define STONELABEL_H
#include <QLabel>
#include <QMouseEvent>  // 包含鼠标事件类
class StoneLabel:public QLabel
{
    Q_OBJECT
public:
    StoneLabel(QWidget* parent);

    /*The mode of stone,such as jewellery,fruit and vegetable*/
    inline void setrow(int row){
        this->row=row;
    }
    inline void setcol(int col){
        this->col=col;
    }
    inline int getrow(){
        return this->row;
    }
    inline int getcol(){
        return this->col;
    }
    inline void setIndex(int index){
        this->index=index;
    }
    inline int getIndex(){
        return this->index;
    }
    inline void setpix(std::string pix){
        this->pix=pix;
    }
    inline std::string getpix(){
        return pix;
    }
    inline void setStyle(int mode=0){
        if(mode==1)
            this->setStyleSheet("background-color: lightblue;");
        else
            this->setStyleSheet(originalStyleSheet);
    }
    bool matched = false;  // 是否匹配，用于消除

    int rowMatchNum = 1;
    void setRowMatchNum(int countRow) { rowMatchNum = countRow; }
    int colMatchNum = 1;
    void setColMatchNum(int countCol) { colMatchNum = countCol; }

    int matchNum = 1;
    void setMatched(bool matchedStatus) { matched = matchedStatus; }
    bool isMatched() const { return matched; }
    void setMatchNum(int matchNumber){ matchNum = matchNumber; }

    bool isFrozen = false;  // 标记是否是冰块
    int lineKiller = 0;  // 标记是否是linekiller，0不是，1横劈，2竖劈

    QString originalStyleSheet = "";  // 记录样式状态

    void setOriginalStyleSheet(const QString &style) {//设置样式状态
        originalStyleSheet = style;
    }

    void setStyleSheetForFrozen() {
        // 设置为黑色填充的样式，代表冰冻状态，可根据实际进一步调整样式细节，比如边框等
        this->setStyleSheet("background-color: black;");
    }

    void setStyleSheetForNormal() {
        // 恢复正常的样式，这里调用父类的默认样式设置（清除之前设置的特殊样式）
        QLabel::setStyleSheet("");
    }

    void setStyleSheetForRowKiller() {
        // 设置为黄色填充的样式，代表横劈，可根据实际进一步调整样式细节，比如边框等
        this->setStyleSheet("background-color: yellow;");
    }

    void setStyleSheetForColKiller() {
        // 设置为绿色填充的样式，代表竖劈，可根据实际进一步调整样式细节，比如边框等
        this->setStyleSheet("background-color: green;");
    }


    void setLineKiller(int value) { lineKiller = value; }

    //目标位置
    int targetX=0;
    int targetY=0;
    static std::string stoneMode;

    bool isSelectedAndEliminated = false;// 标记该棋子是否在本轮被鼠标选中且发生了消除

    void setSelectedAndEliminated(bool value) {// 设置是否被选中且消除的函数
        isSelectedAndEliminated = value;
    }
private:
    int row;
    int col;
    int index=0;

    std::string pix;//保存图片信息


};

#endif // STONELABEL_H

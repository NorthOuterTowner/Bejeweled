#include "utils.h"
#include <QCryptographicHash>
#include <QString>

// 使用 SHA-256 加密密码
QString utils::hashPassword(const QString &password) {
    // 将字符串转换为 UTF-8 字节数组
    QByteArray byteArray = password.toUtf8();
    // 使用 QCryptographicHash 计算 SHA-256
    QByteArray hashedArray = QCryptographicHash::hash(byteArray, QCryptographicHash::Sha256);
    // 将加密结果转换为十六进制字符串并返回
    return QString(hashedArray.toHex());
}
utils::utils() {}

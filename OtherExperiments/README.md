# 其他技术实验

原始代码中独立的技术练习。按内容分类整理，未主动修复原算法逻辑或已知错误。

| 文件 | 内容 | 原始位置 |
|---|---|---|
| [`FixedPointConversion.cpp`](FixedPointConversion.cpp) | 定点数据位运算转换 | `CppPrimer.cpp:529-573` |
| [`FrequencyBandEdges.cpp`](FrequencyBandEdges.cpp) | 频率上下边界 | `CppPrimer.cpp:499-524` |
| [`WritePimcDataToFile.cpp`](WritePimcDataToFile.cpp) | PIMC 文件输出（依赖项目类型和宏） | `CppPrimer.cpp:435-451` |

`WritePimcDataToFile.cpp` 依赖原工程中的 `U32`、日志宏等，并非独立运行示例。

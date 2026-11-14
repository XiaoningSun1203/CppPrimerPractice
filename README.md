# CppPrimerPractice

将原根目录 `CppPrimer.cpp` 和本地 `main1.cpp`、Chapter 练习统一按《C++ Primer》章节整理。所有原始版本仍可从 Git 历史恢复。

- [C++ Primer](CppPrimer/README.md)：59 个 C++ 源文件
- [Algorithms](Algorithms/README.md)：7 个源文件，BFS/DFS 保持同一文件
- [OtherExperiments](OtherExperiments/README.md)：3 个源文件
- [Protobuf](Protobuf/)：保留原结构

## C++ Primer 章节索引

| 章节 | 文件数量 | 目录 |
|---|---:|---|
| Chapter02 | 6 | [`Chapter02`](CppPrimer/Chapter02/) |
| Chapter03 | 14 | [`Chapter03`](CppPrimer/Chapter03/) |
| Chapter06 | 4 | [`Chapter06`](CppPrimer/Chapter06/) |
| Chapter07 | 1 | [`Chapter07`](CppPrimer/Chapter07/) |
| Chapter08 | 9 | [`Chapter08`](CppPrimer/Chapter08/) |
| Chapter09 | 7 | [`Chapter09`](CppPrimer/Chapter09/) |
| Chapter10 | 10 | [`Chapter10`](CppPrimer/Chapter10/) |
| Chapter11 | 3 | [`Chapter11`](CppPrimer/Chapter11/) |
| Chapter12 | 2 | [`Chapter12`](CppPrimer/Chapter12/) |
| Chapter13 | 2 | [`Chapter13`](CppPrimer/Chapter13/) |
| Chapter15 | 1 | [`Chapter15`](CppPrimer/Chapter15/) |

## 原代码保留规则

- 原来的 `CppPrimer.cpp` 已拆分到章节文件中，并从当前根目录移除，防止多份同源代码并存；Git 提交历史保留该原文件。
- 恢复了 `main1.cpp` 中为切换运行而禁用的代码，尽可能保留原有代码注释和写法。
- 只补充拆分所需的头文件等最低限度调整；故意错误示例、未完成代码和依赖项目环境的代码不强行改成可编译程序。
- 原有 `Protobuf/` 内容不变。

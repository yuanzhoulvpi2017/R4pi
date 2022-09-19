## 介绍
1. 使用蒙特卡洛方法计算圆周率pi
2. 这个算法是写到C++里面的，然后让R来调用

### 为什么要写这个
1. 前几天，写了一个比较rust、c、python、R计算速度的代码。一大堆人说：“R不能用for、R可以向量化”。我能不知道？当然，我觉得这说的都很正常，毕竟是正常讨论。
2. 但是有些人张口就来，说我是黑R语言，我尼玛，把我说笑了。真是沙雕。
3. R语言作为一个编程语言，拿出来和各种语言比较是非常正常不过的事情了，在我眼里就是玩具（没有贬低的意思，虽然我也很菜，但是就是喜欢玩代码）。
4. 晚上想尝试使用C++开发R的流程，顺带写了这个小demo，打卡记录一下。




## benchmark

打开`tools`文件夹📁下的`debug.R`文件，逐行运行即可，下面是部分代码片段

```R
library(rbenchmark)

benchmark(
    "lm" = {
        value <- calculate_p_init(100000000L)
    },
    replications = 10,
    columns = c(
        "test", "replications", "elapsed",
        "relative", "user.self", "sys.self"
    )
)
#>   test replications elapsed relative user.self sys.self
#> 1   lm           20  29.467        1    29.422    0.017
```



## 说明
1. 这个仓库基于 https://github.com/DavisVaughan/vsexample 修改的。

## ps
1. `vscode`同时写`R`、`C++`是真爽～
2. 我后面试一试`vscode`同时写`python`、`C++`

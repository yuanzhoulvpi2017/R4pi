# use this package
devtools::clean_dll()
devtools::load_all()


# first try

value <- calculate_p_init(100000L)
value


# benchmark
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

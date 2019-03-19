# simple-country-statistic
job interview solution
***
## Формат входных данных

`user_id;count;country`

Например:

```
11231;6;Russia
11232;1;Ukraine
1122;1;Ukraine
```

Предусмотреть устойчивость программы к ошибке формата, если строка не соответствует формату, она пропускается.
***
## Формат выходных данных

`country;sum(count) (сумма по count);count_uniq(user_id) (число уникальных user_id для country)`

## Использование

В директории проекта выполнить

`make`

`./prog <input ile> <output file>`

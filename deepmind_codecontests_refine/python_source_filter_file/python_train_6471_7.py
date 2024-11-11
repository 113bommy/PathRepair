N = int(input())
beg = 0
end = 9
i = 0  # в скольки значных числах мы находимся - 1


while N > end:
    i += 1
    beg, end = end, end + (i + 1) * 9 * 10**i

n = N - beg - 1  # это N относительно начала чисел с длинной i, начиная с 0
lvl = i - n % (i + 1)  # номер симвала, начиная от конца числа
period = (i + 1) * 10**lvl  # период смены числа

res = n//period
if lvl == i:
    res += 1
print(res)

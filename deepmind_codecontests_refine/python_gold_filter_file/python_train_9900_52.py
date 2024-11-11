a = input()
lst = []
a_1 = ""
for i in range(len(a)):
    if a[i] != " ":
        a_1 = a_1 + a[i]
    else:
        lst.append(int(a_1))
        a_1 = ""
lst.append(int(a_1))
if lst[1] > 2 * lst[0] - 1:
    print(0)
else:
    countr = 0
    if lst[1] % 2 == 1:
        countr = (lst[1] - 1) // 2
    else:
        countr = (lst[1] - 2) // 2
    if lst[1] > lst[0] + 1:
        countr = countr - lst[1] + lst[0] + 1
    print(countr)
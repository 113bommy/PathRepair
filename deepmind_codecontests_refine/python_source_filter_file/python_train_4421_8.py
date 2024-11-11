n = int(input())
a = [int(x) for x in input(). split()]
s, p, flag = 0, 0, False
for i in range(n):
    if a[i] == 1 and p < 2:
        s += 1
        p, flag = 0, True
    elif a[i] == 1:
        s += 2
        p, flag = 0, True
    elif flag:
        p += 1
print(s)
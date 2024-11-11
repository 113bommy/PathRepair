n = int(input())
for i in range(n):
    c, s = map(int, input().split())
    if c == 1 :
        print(s)
    else:
        num = s // c
        ost = s - num * c
        print((c - ost) * num * num + ost * (num + 1) * (num + 1))

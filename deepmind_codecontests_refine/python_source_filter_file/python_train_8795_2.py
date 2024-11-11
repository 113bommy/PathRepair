n = int(input())
a = list(map(int, input().split()))
ans = 0
limak = a[0]
a = a[1:]
a.sort()
mx_add = sum(a)
for i in range(mx_add):
    cur_add = 0
    for j in range(len(a)):
        if a[j] >= limak + i:
            cur_add += a[j] - (limak + i - 1)
    if cur_add <= i:
        print(i)
        exit(0)
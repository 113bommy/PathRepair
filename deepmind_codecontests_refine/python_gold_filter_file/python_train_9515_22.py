n = int(input())
a = list(map(int, input().split()))
num = 0
for i in range(n):
    for j in range(i, n):
        tmp = 0
        for k in range(n):
            if i <= k <= j:
                if a[k] == 0:
                    tmp += 1
            else:
                if a[k] == 1:
                    tmp += 1
        num = max(num, tmp)
print(num)

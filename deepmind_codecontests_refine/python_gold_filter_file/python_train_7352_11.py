n = int(input())
a = list(reversed(list(map(int, input().split()))))
b = a[0]
res = 1
for i in range(1,n):
    if b:
        if a[i]>=b:
            b = a[i]
        else:
            b-=1
        continue
    res += 1
    b = a[i]
print(res)
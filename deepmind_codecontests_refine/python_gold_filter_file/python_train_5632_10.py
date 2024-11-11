n, m = map(int, input().split())
temp = list(map(int, input().split()))
temp2 = set(temp)
a = {int(i) : temp.count(i) for i in temp2}
res = 0

for i in range(1, m + 1):
    temp = n
    for j in a:
        temp -= a[j] // i
        if temp <= 0:
            res = i
            break
    else:
        break

print(res)
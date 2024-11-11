n = int(input())
x = list(map(int, input().split()))
sorted_x = sorted(x)

if sorted_x[n // 2] == sorted_x[n // 2 - 1]:
    ret = [sorted_x[n // 2]] * n
else:
    ret = []
    for i in range(n):
        if x[i] >= sorted_x[n // 2]:
            ret.append(sorted_x[n // 2])
        else:
            ret.append(sorted_x[n // 2 - 1])
for i in ret:
    print(i)

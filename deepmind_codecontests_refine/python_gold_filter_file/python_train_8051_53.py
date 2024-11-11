n = int(input())
arr_p = list(map(int, input().split()))
sum = 0
for i in range(n):
    sum += arr_p[i]
ans = sum / n
print('%.6f' % ans)
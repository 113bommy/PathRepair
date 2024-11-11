import math

n, vb, vs = map(int, input().split())
x = list(map(int, input().split()))
xu, yu = map(int, input().split())

min_time = x[1] / vb + math.sqrt((xu - x[1]) ** 2 + yu ** 2) / vs
ans = 2
min_x = x[1]

for i in range(2, n):
    time = x[i] / vb + math.sqrt((xu - x[i]) ** 2 + yu ** 2) / vs

    if time < min_time and abs(min_x - xu) > abs(x[i] - xu):
        min_time = time
        min_x = i
        ans = i + 1
        
print(ans)
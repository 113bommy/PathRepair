n, m = map(int, input().split())
x = [x for x in map(int, input().split())]
y = [y for y in map(int, input().split())]
sum_x = 0
sum_y = 0
ans = 0
for i in range(n):
    sum_x += (2*i - n + 1) * x[i+1] 
for j in range(m):
    sum_y += (2*j - m + 1) * y[j+1]
ans = sum_x * sum_y
print(ans%1000000007)
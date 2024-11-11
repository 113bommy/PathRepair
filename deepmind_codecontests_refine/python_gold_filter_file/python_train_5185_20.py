n, d = map(int, input().split())
count = 0
x_list = [list(map(int, input().split())) for _ in range(n)]

for i in range(n-1):
    for j in range(i+1, n):
        count += (sum((a-b)**2 for a,b in zip(x_list[i], x_list[j]))**0.5).is_integer()
print(count)
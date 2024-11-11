n = int(input())
data = [int(i) for i in input().split(' ')]
moves = n - 1
for i in range(moves):
    if (i % 2 == 0):
        tmpmax = max(data)
        data.remove(tmpmax)
    else:
        tmpmin = min(data)
        data.remove(tmpmin)
print(data)

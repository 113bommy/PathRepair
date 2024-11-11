n = int(input())
cities = [0 for _ in range(n + 1)]
x = list(map(int, input().split(' ')))
total = [0] + list(map(int, input().split(' ')))
ans = 0
for i in range(n, 0, -1):
    if(cities[i] == 0):
        cities[i] = 1
    if(i >= 2):
        cities[x[i - 2]] += cities[i]
        total [x[i - 2]] += total[i]
    ans = max(ans, (total[i] + cities[i] - 1 // cities[i]))
print(ans)
n, k = list(map(int, input().split()))

teams = []
for _ in range(n):
    teams.append(list(map(int, input().split())))

teams.sort(key=lambda x: x[0]*100 - x[1], reverse=True)

count = 0

kth = teams[k-1][0]*100 + teams[k-1][1]
for t in teams:
    if t[0]*100 + t[1] == kth:
        count += 1
print(count)

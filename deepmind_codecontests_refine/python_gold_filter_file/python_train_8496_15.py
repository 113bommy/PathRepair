n = int(input())
day = 0
for i in range(n):
    s, d = map(int, input().split(" "))
    
    day = max(day + 1, s)
    while (day - s) % d != 0:
        day += 1
print(day)
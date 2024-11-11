n = int(input())
m = list(map(int, input().split()))
r = list(map(int, input().split()))

days = 0

for day in range(1, 100001):
    for index in range(n):
        if day % m[index] == r[index]:
            days += 1
            break

print(days / 100000)

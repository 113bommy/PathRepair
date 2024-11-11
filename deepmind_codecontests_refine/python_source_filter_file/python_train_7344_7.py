n,b,d = map(int, input().split())
a = list(map(int, input().split()))

sum = 0
res = 0
for value in a:
    if value <= b:
        sum += value
    if sum > d:
        sum = sum - d
        res += 1

print(res)

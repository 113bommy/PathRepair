n, p = map(int, input().split(' '))
ps = [True if input() == "halfplus" else False for _ in range(n)]

t = 0
result = 0

for x in reversed(ps):
    if x:
        t += 0.5
    result += t
    t *= 2

print(int(result * p))
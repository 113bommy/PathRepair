n, p = map(int, input().split(' '))
ps = [True if input() == "halfplus" else False for _ in range(n)]

t = 1
result = 0.5

for x in reversed(ps[1:]):
    if x:
        t += 0.5
    result += t
    t *= 2

print(int(result * p))

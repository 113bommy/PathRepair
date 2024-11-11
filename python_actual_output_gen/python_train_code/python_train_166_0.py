p, n = {}, int(input())
t = list(map(int, input().split()))
for i in t:
    j = format(i, 'b').count('1')
    p[j] = p.get(j, 0) + 1
print(sum(x * (x + 1) for x in p.values()) // 2)
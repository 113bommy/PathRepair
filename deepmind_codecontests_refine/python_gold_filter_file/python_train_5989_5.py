def factor(n):
    res = 1
    for i in range(1, n+1):
        res *= i
    return res
        
n = int(input())
p = []
res = 0

for i in range(n):
    p.append(list(input()))
    c = p[i].count('C')
    res += factor(c)/(2*factor(c-2)) if c > 1 else 0

for col in list(zip(*p)):
    c = col.count('C')
    res += factor(c)/(2*factor(c-2)) if c > 1 else 0

print(int(res))
nmab = list(map(int, input().split()))
n = nmab[0]
m = nmab[1]
a = nmab[2]
b = nmab[3]
p = m/b
if p<a :
    t = 0
    s = 0
    while t < n:
        if t+m > n:
            if b < a*(n-t):
                s += b
                break
            else:
                s += a*(n-t)
                break
        else:
            t += m
            s += b
else:
    s = n*a
print(s)
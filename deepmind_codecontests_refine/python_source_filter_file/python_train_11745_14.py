# coding: utf-8

n,x = map(int, input().split())

l,p = [1],[1]
for i in range(n):
    l.append(a[i]*2+3)
    p.append(a[i]*2+1)

def f(n,x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + l[n-1]:
        return f(n-1,x-1)
    else:
        return p[n-1]+1+f(n-1,x-2-l[n-1])

print(f(n,x))

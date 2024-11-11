a,b,c = [int(x) for x in input().split()]
d,e,f = [int(x) for x in input().split()]
g,h,i = [int(x) for x in input().split()]

n = int(input())
S = {int(input()) for x in range(n)}

def f(x,y,z):
    return x in S and y in S and z in S

print('Yes' if f(a,b,c) or f(d,e,f) or f(g,h,i) or f(a,d,g) or f(b,e,h) or f(c,f,i) or f(a,e,i) or f(g,e,c) else 'No')

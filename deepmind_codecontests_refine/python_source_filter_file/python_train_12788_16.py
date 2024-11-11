a,b,c,d,e,f = map(int,input().split())
w = set()
for x in range(0,f+1,100*a):
    for y in range(0,f+1-x,100*b):
        w.add(x+y)
s = set()
for x in range(0,f+1,c):
    for y in range(0,f+1-x,d):
        s.add(x+y)
ans = 0
sugerwater = 0
suger = 0
for x in w:
    for y in s:
        if  0<x+y<=f and y <= x*e//100:
            if ans < y/(x+y):
                ans = y/(x+y)
                sugerwater = x+y
                suger = y
print(sugerwater,suger)

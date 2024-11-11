a,b,c,d,e,f=map(int,input().split())
w=set()
for i in range(0,f,100*a):
    for j in range(0,f,100*b):
        if i+j<=f:
            w.add(i+j)
        else:
            break
s=set()
for i in range(0,f,c):
    for j in range(0,f,d):
        if i+j<=f:
            s.add(i+j)
        else:
            break
n=0
m=0
l=0
for x in w:
    for t in s:
        if x+t!=0 and x+t<=f and 100*t<=e*x and t/(x+t)>l:
            n=x+t
            m=t
            l=t/(x+t)
print(n,m)

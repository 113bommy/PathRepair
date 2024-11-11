n=0
h,w,d=map(int,input().split())
x=[0]*(h*w)
y=[0]*(h*w)
for i in range(h):
    for a in input().split():
        A=int(a)-1
        x[A]=n%w
        y[A]=n//h
        n+=1
        
c=[0]*(h*w)
for i in range(h*w):
    if i>=d:
        c[i]=c[i-d]+abs(x[i]-x[i-d])+abs(y[i]-y[i-d])
q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    print(c[r-1]-c[l-1])

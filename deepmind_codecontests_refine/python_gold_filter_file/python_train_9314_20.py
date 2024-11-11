n,a,b=list(map(int,input().split()))
s=set()
while n:
    n=n-1
    x,y=list(map(int,input().split()))
    if(x==a):
        s.add('a')
        continue
    s.add((y-b)/(x-a))
print(len(s))        
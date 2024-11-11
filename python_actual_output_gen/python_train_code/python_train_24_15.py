a,b=map(int,input().split())
t=list(map(int,input().split()))
maxx=0
for i in t:
    if b%i==0 and i>maxx:
        maxx=i
print(b/i)
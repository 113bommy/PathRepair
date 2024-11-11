x,y=map(int,input().split())

res=0

for n in range(x):
    a,b=map(int,input().split())
    d=(a*a +b*b)**.5
    if d>=y:res+=1

print(res)
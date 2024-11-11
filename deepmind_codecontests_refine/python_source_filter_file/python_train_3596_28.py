n,x=map(int, input().split())
count=0
for i in range(n):
    s,r=map(str, input().split())
    d=int(r)
    if s=='+':
            x+=d
    else:
        if x>d:
            x-=d
        else:
            count+=1
print(x,count)
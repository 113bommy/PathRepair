n=int(input())
l=list(map(int,input().split()))
m=-1
x=0
for i in l:
    if(i==1):
        x=x-1
    else:
        x=x+1
    if(x>m):
        m=x
    if(x<0):
        x=0
print(sum(l)+m)

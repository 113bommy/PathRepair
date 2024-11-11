t=int(input())
c=0
while(t>0):
    t-=1 
    p,q=list(map(int,input().split()))
    if(q-p>=2):
        c=+1
print(c)
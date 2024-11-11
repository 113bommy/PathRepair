v = int(input())
a=list(map(int,input().split()))
m,j=a[0],0
for i,x in enumerate(a,1):
    if x<=m: m,j=x,i
x=int(v/m)
if(x==0):
    print(-1)
else:
    while x:
        x-=1
        i=9
        while i:
            i-=1
            if ((v>=a[i])&(int((v-a[i])/m) == x)):
                v-=a[i]
                print(i+1,end='')
                break
        if i+1==j:
            break
    print(x*str(j))
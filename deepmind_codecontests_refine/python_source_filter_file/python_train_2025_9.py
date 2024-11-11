n=int(input())
a=list(map(int,input().split()))
c1=0
c2=0
x=[]
for i in range(1,n):
        if(a[i]>a[i-1]):
                c1+=1
        else:
                x.append(i)
                c2+=1
if(a[n-1]>a[0] and c2!=0):
        c2=2
if(len(x)==0):
        x=[n]
if(c2<=1):
        print(n-x[0])
else:
        print(-1)

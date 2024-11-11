n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
x=b[0]
y=b[1]
i=0
s=sum(a)
ans1=0
ans2=s
ans=0
while i<n:
    ans1+=a[i]
    ans2-=a[i]
    ##print(ans1,ans2,i)
    if (ans1>=x and ans1<=y) and (ans2>=x and ans2<=y):
        print(i+1)
        ans=1
        break
    i+=1
if ans==0:
    print(0)

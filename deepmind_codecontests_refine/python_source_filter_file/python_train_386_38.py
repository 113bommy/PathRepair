def read():
    return list(map(int,input().split()))
n=int(input())
a=read()
j=0
ans1=0
for i in range(1,n+1,2):
    ans1+=abs(a[j]-i)
    j+=1
j=0
ans2=0
for i in range(2,n+1,2):
    ans2+=abs(a[j]-i)
    j+=1
print(min(ans1,ans2))

    
    

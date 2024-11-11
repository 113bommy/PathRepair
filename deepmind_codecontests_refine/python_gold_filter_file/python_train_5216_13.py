# левый догоняет правый индекс поэтому 0(n)
n = int(input())
a = list(map(int,input().split()))
L,R,ans=0,0,1
while True:
    if R==n-1:
        ans=max(ans,R-L+1)
        break
    if a[R]*2>=a[R+1]:
        R+=1
    else:
        ans=max(ans,R-L+1)
        R+=1
        L=R
print(ans)
        

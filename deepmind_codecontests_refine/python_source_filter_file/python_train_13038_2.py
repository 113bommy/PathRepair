t=int(input())
ans=[]
for i in range(t):
    a=list(map(int,input().strip().split()))
    if ((a[0]*a[1])%2!=0):
        ans.append((a[0]*a[1]//2)+1)
    else:
        ans.append((a[0]*a[1])/2)
for i in ans:
    print(i)
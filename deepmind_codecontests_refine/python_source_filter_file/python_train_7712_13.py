n = int(input())
lis = list(map(int,input().split()))
pre=[0]*(n)
pos=[0]*(n)
for i in range(n-1):
    pre[i]=pre[i-1]+lis[i]
    pos[i]=pos[i-1]+lis[n-i-1]
for i in range(n-2,-1,-1):
    l=0
    r=n-i-1
    while r>=l:
        mid = l + (r-l)//2
        if pos[mid]<=pre[i]:
            l=mid+1 
        else:
            r=mid-1
    if pos[r]==pre[i]:
        print(pos[r])
        exit()
print(0)        

            
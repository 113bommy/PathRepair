n=int(input())
arr=list(map(int,input().split()))
pre,pre1=[1],[1]
for i in range(1,n):
    if arr[i]>arr[i-1]:
        pre.append(pre[-1]+1)
    else:
        pre.append(1)
arr.reverse()
for i in range(1,n):
    if arr[i]<arr[i-1]:
        pre1.append(pre1[-1]+1)
    else:
        pre1.append(1)
pre1.reverse()
arr.reverse()
ans=1
for i in range(n):
    if i>0 and i<n-1 and arr[i-1]<arr[i+1]-1:
        ans=max(ans,pre[i-1]+pre1[i+1]+1)
        #print(*[i,pre[i-1]+pre1[i+1]+1])
    if i>0:
        ans=max(ans,pre[i-1]+1)
    if i<n-1:
        ans=max(ans,pre1[i+1]+1)
print(ans)

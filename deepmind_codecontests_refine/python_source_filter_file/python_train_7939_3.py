n=int(input())
arr = list(map(int,input().split()))
arr.sort()
ans = [-1]*n
k=0
c=0
for i in range(1,n-1,2):
    ans[i]=arr[k]
    k+=1
for i in range(n):
    if ans[i]==-1:
        ans[i]=arr[k]
        k+=1
for i in range(1,n-1,2):
    if ans[i]<ans[i-1] and ans[i]<ans[i+1]:
        c+=1
print (c)
for i in range(n):
    print(ans[i],end=' ')

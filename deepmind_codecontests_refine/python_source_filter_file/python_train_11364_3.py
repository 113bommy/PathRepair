n=int(input())
lst=list(map(int,input().split()))
x=[]
# x=lst
for i in range(n):
    x.append(lst[i])

x.sort()
ans=10**100
for i in range(n):
    diff=max(n-i+1,i)
    ans=min(ans,lst[i]//diff)
print(ans)

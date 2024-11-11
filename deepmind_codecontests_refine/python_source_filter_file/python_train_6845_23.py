n,k=map(int,input().split())
arr=list(map(int,input().split()))
m={}
d=[]
c=0
for i in range(n):
    if arr[i] in m:
        c+=1
    else:
        m[arr[i]]=1
        d.append(i+1)
# print(m)
if len(m)>=k:
    print("YES")
    print(*d[:k+1])
else:
    print("NO")

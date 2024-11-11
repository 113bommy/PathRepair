n,k=list(map(int,input().split()))
l=list(map(int,input().split()))
cnt=0
for i in range(n):
    if l[i]<=k:cnt+=1
    else:break
l=l[i+1:]
print(l)
for i in range(-1,-len(l)-1,-1):
    if l[i]<=k:cnt+=1
    else:break
print(cnt)

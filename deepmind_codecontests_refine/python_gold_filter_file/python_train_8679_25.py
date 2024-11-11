n=int(input())
l=list(map(int,input().split()))
l.sort()
j=0
ans=0
for i in range(1,3002):
    if i==l[j]:
        j=j+1 if j<len(l)-1 else j
    else:
        ans=i
        break
print(ans)
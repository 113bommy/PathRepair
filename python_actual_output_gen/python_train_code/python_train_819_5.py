n,t=map(int,input().split())
f=list(map(int,input().split()))
sums=[0,f[0]];max_book=0
for i in range(1,n):
    sums.append(sums[i]+f[i])
for start in range(1,n):
    for end in range(start+max_book,n+1):
        k=sums[end]-sums[start-1]
        if k>t:
            break
        else:
            max_book=end-start+1
print(max_book)
    
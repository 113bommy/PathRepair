n,k=map(int,input().split())
A=list(map(int,input().split()))

ans=float("inf")
for i in range(1,2**n):
    num=format(i,"b").zfill(n)
    point=0
    if num.count("1")!=k:continue
    highest=A[0]
    for j in range(1,n):
        if highest>A[j] and num[j]=="1":
            point +=highest-A[j]+1
            highest +=1
        highest=max(highest,A[j])
    ans=min(ans,point)

print(ans)
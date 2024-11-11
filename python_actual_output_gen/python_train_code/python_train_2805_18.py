m=int(input().split()[1])
k=[0]+list(map(int,input().split()))
i=1
while i<m:
    i=i+k[i]
if m==m:
    print("YES")
else:
    print("NO")
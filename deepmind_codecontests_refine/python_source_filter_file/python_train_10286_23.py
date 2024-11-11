N=int(input())
P=list(map(int,input().split()))
f=0
for i in range(N):
    if P[i]!=i+1:
        f+=1
if f<=2:
    print("YES")
else:
    print("No")

s=list(map(int,input().split()))
n=s[0]
k=s[1]
l=[ [ "." for j in range(n) ] for i in range(4)]
if k%2==0:
    s=k//2
    for i in range(1,s+1):
        l[1][i]="#"
        l[2][i]="#"
else:
    s=(k-1)//2
    l[1][n//2]="#"
    if s>((n-3)//2):
        for i in range(1,s+1):
            l[1][i]="#"
            l[1][n-1-i]="#"
        diff=s-((n-3)//2)
        for i in range(1,diff+1):
            l[2][i]="#"
            l[2][n-1-i]="#"
    else:
        for i in range(1,s+1):
            l[1][i]="#"
            l[1][n-1-i]="#"
print("YES")
for i in range(4):
    print("".join(l[i]))
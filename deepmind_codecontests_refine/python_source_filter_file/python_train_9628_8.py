n,k = list(map(int,input().split()))
ans = 0
for i in range(1,n+1):
    ans+=i
    if i%2==0: ans-=1

if ans<k:print("NO");exit()

print("YES")

f = 0
for i in range(n):
    for j in range(n):
        if f==0 and j%2 and k>0: print('L',end="");k-=1
        elif f==1 and j%2==0 and k>0 : print('L',end="");k-=1
        else: print('S',end="")
    f^=0
    print()

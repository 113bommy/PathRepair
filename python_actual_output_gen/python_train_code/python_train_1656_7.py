N=int(input())
def cou(n,x):
    i=0
    while(n>0):
        i+=n%x
        n//=x
    return i
ans=N
for i in range(N+1):
    ans=min(ans,cou(j,6)+cou(N-j,9))
print(ans)
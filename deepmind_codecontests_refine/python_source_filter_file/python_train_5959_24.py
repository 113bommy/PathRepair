import sys
n,m,k=map(int,sys.stdin.readline().split())
for i in range(2*k):
    l=list(map(int,sys.stdin.readline().split()))
ans=""
ans+=(m-1)*'L'
ans+=(n-1)*'D'
ans+=(n-1)*'U'
for i in range(m-1):
    if i%2==0:
        ans+='R'
        ans+=(n-1)*'D'
    else:
        ans+='R'
        ans+=(m-1)*'U'
print(len(ans))
print(ans)

    
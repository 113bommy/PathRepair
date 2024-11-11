n=int(input())
L=list(map(int,input().split()))
def solve(L,k):
    if k==0:
        if 0 in L and 1 in L:return 1
        else:return 0
    bit=2**k
    L0=[]
    L1=[]
    for i in L:
        if i>bit:L1.append(i-bit)
        else:L0.append(i)

    if L0==[]:return solve(L1,k-1)
    if L1==[]:return solve(L0,k-1)
    sol0=solve(L0,k-1)
    sol1=solve(L1,k-1)
    return min(sol0,sol1)+bit
m=max(L)
count=0
while m>1:
    m//=2
    count+=1
print(solve(L,count))
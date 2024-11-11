from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int, stdin.readline().split()))
def fn(p):
    turns=b[p]//14
    a=b.copy();sm=0
    a[p]=0
    for i in range(1,15):
        a[(p+i)%14]+=turns
    rem=b[p]%14
    for i in range(p+1,p+rem+1,1):
        a[(i%14)]+=1
    for i in range(14):
        if i!=p and a[i]&1==0:
            sm+=a[i]
    # print(a)
    return sm
for _ in range(1):#nmbr()):
    b=lst()
    ans=0
    for i in range(14):
        if b[i]!=0:ans=max(ans,fn(i))
    print(ans)

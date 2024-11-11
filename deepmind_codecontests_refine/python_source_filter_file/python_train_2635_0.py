import math
def getint():
    return [int(i) for i in input().split()]
def getstr():
    return [str(i) for i in input().split()]
#--------------------------------------------------------------------------
def solve():
    n=int(input())
    a=getint()
    ans=""
    l=0
    for i in range(n-1,-1,-1):       
        if a[i]==0:
            if l<=n-1-i:
                ans+="0"
                l+=1
        else:
            leng=min(a[i]-l+n-1-i,n-l)
            if leng<0:
                leng=0
            l+=leng
            ans+="1"*leng
        print(i,ans)
    print(" ".join(ans[::-1]))
#--------------------------------------------------------------------------
for _ in range(int(input())):
    solve()

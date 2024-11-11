import math
import cmath

n,m,v=0,0,[]


def solve():
    global m,v
    st,dr=0,m-1
    while st<dr:
        md=st + dr>>1
        ok=1
        cur=0
        for x in v:
            if(x+md>=m):
                if(cur<=x and cur<= x+md-m):
                    continue
                else:
                    cur=int(x)
            else:
                if(cur>x+md):
                    ok=0
                    break
                elif(cur<x):
                    cur=int(x)
        if(ok==1):
            dr=md
        else:
            st=md+1
    return st 


def main():
    global n,m,v
    n,m = (int(x) for x in input().split())
    v = list(int(x) for x in input().split())
    ans=solve()
    print(ans)

if __name__=="__main__":
    main()

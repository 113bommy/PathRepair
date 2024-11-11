from bisect import *


def rnum():
    return int(input())


def rnums():
    return map(int, input().split())


def rlist():
    return list(map(int, input().split()))


def solve():
    n=rnum()
    mas=rlist()
    k=rnum()

    if(sum(mas)+k*(n//2)>0):
        print(n)
        return

    if(k>=0):
        print(-1)
        return

    pref=[0]*n
    pref[0]=mas[0]

    for i in range(1,n//2+n%2):
        pref[i]=pref[i-1]+mas[i]

    for i in range(n//2+n%2,n):
        pref[i]=pref[i-1]+k

    minn=pref[n-1]

    for i in range(n//2):
        minn=min(pref[n-1]-pref[i],minn-k)
        if(minn>0):
            print(n-i-1)
            return
    print(-1)





def main():
    t = 1
    for i in range(t):
        solve()


main()

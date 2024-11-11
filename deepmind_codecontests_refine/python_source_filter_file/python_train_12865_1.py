import sys

input = sys.stdin.readline

mod = 1000000007


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


def main():
    n,m=map(int, input().split())
    a=[]
    fei=[]
    maxi=[1 for i in range(n)]
    for i in range(n):
        a.append(list(map(int, input().split())))
        fei.append([1 for j in range(m)])

    for j in range(m):
        prev=0
        for i in range(1,n):
            if a[i][j]<=a[i-1][j]:
                fei[i][j]=fei[i-1][j]+1
                maxi[i]=max(maxi[i], fei[i][j])

    k=int(input())
    while(k):
        l,r=map(int, input().split())
        l-=1
        r-=1
        if maxi[r]>=r-l+1:
            print('Yes')
        else:
            print('No')
        k-=1
    return


if __name__ == "__main__":
    main()

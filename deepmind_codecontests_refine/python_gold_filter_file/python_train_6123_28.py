import sys
sys.setrecursionlimit(10**5)

def main():
    n=int(input())
    nodes=[[]for _ in range(n)]
    mod=10**9+7

    for _ in range(n-1):
        x,y=map(int,input().split())
        nodes[x-1].append(y-1)
        nodes[y-1].append(x-1)

    def pick(n,excep=-1):
        white=1
        black=1
        for node in nodes[n]:
            if excep==node:
                continue
            p=pick(node,n)
            white=(white*(p[0]+p[1]))%mod
            black=(black*p[0])%mod
        return [white,black]
    p=pick(0)
    print(sum(p)%mod)
main()
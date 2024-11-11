import sys
def main():
    input = sys.stdin.readline
    N,K,Q=map(int, input().split())
    *A,=map(int, input().split())

    ans=10**10
    from heapq import heappop, heappush
    A.append(-1)
    for y in A:
        if y==-1: break
        c=[]
        t=[]
        for a in A:
            if a >= y:
                heappush(t, a)
            else:
                for _ in range(len(t)-(K-1)):
                    heappush(c, heappop(t))
                t.clear()
        if len(c) < Q: continue
        x=[heappop(c) for _ in range(Q)][-1]
        ans = min(ans, x-y)
    print(ans)

if __name__ == '__main__':
    main()
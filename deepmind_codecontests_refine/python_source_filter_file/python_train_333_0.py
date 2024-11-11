import sys
def main():
    def input():
        return sys.stdin.readline()[:-1]
    n, l = map(int,input().split())
    a = list(map(int,input().split()))
    ans = 10000000
    b = [[] for k in range(max(a)+1)]
    for e in a:
        t = 0
        b[e].append(0)
        while e > 0:
            e //= 2
            t += 1
            b[e].append(t)
    for k in range(max(a)+1):
        if len(b[k]) >= l:
            ans = min(ans,sum(sorted(b[k][:l])))
    print(ans)

if __name__ == '__main__':
    main()

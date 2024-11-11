import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def main():
    N = int(input())
    X = list(enumerate(map(int,input().split())))
    X.sort(key = lambda x:x[1])
    
    M = N*N
    ans = [None] * M
    now = 0
    for i,x in X:
        ans[x - 1] = i + 1
        count = i
        while count > 0:
            while ans[now]:
                now += 1
            if now >= x:
                print('No')
                return
            ans[now] = i + 1
            count -= 1
    
    now = M - 1
    for i,x in X[::-1]:
        count = N - i - 1
        while count > 0:
            while ans[now]:
                now -= 1
            if now <= x:
                print('No')
                return
            ans[now] = i + 1
            count -= 1
    print('Yes')
    print(' '.join(map(str,ans)))
if __name__ == '__main__':
    main()
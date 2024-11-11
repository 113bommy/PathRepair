import sys
input = sys.stdin.readline
sys.setrecursionlimit(pow(10, 6))

def main():
    n = int(input())
    a = [(i, _a) for i, _a in enumerate(map(int, input().split()))]
    a.append((n, 0))
    ans = [0 for _ in range(n)]
    a = list(sorted(a, key=lambda x: (-x[1], x[0])))
    mini = a[0][0]
    for j, _a in enumerate(a):
        if j>0 and a[j-1][1] != _a[1]:
            ans[mini] += a[j-1][1] - _a[1] + j-1
            mini = min(mini, a[j][0])
    print(*ans, sep='\n')


if __name__ == '__main__':
    main()

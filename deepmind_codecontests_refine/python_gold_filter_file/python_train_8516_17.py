import sys
input = sys.stdin.readline

def main():
    N = int(input())
    S = input().rstrip()
    Q = int(input())
    k = list(map(int, input().split()))

    for l in k:
        D = 0
        M = 0
        tmp = 0
        ans = 0
        for i in range(N):
            if i >= l:
                if S[i-l] == 'D':
                    tmp -= M
                    D -= 1
                if S[i-l] == 'M':
                    M -= 1
            if S[i] == 'D':
                D += 1
            if S[i] == 'M':
                M += 1
                tmp += D
            if S[i] == 'C':
                ans += tmp
        print(ans)

main()
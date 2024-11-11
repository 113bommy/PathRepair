def main():
    import sys
    input = sys.stdin.readline
    N = int(input())
    S = input()
    _ = int(input())
    K = [int(i) for i in input().split()]

    def solve(k):
        cd = 0
        cm = 0
        cdm = 0
        ans = 0
        for i in range(N):
            if S[i] == 'D':
                cd += 1
            elif S[i] == 'M':
                cm += 1
                cdm += cd
            elif S[i] == 'C':
                ans += cdm
            if k - 1 <= i:
                if S[i-k+1] == 'D':
                    cdm -= cm
                    cd -= 1
                if S[i-k+1] == 'M':
                    cm -= 1
        return ans

    for k in K:
        print(solve(k))


if __name__ == '__main__':
    main()

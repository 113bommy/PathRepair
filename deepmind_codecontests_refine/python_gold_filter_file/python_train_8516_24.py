def main():
    import sys
    input = sys.stdin.readline

    n = int(input())
    s = input()
    _q = int(input())
    
    for k in map(int,input().split()):
        res = 0
        p = 0
        cnt = 0
        q = 0
        for i in range(n):
            if i >= k:
                if s[i-k] == 'D':
                    cnt -= 1
                    p -= q
                elif s[i-k] == 'M':
                    q -= 1

            if s[i] == 'D':
                cnt += 1
            elif s[i] == 'M':
                p += cnt
                q += 1
            elif s[i] == 'C':
                res += p
        print(res)

if __name__ == '__main__':
    main()
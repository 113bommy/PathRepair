def main():
    import sys
    from collections import defaultdict
    input = sys.stdin.readline

    mod = 10**9+7
    mod2 = 10**9+9
    mod3 = 998244353
    N, L = map(int, input().split())
    dic = defaultdict(int)
    dic2 = defaultdict(int)
    dic3 = defaultdict(int)
    h_list = []
    h2_list = []
    h3_list = []
    pair = {}
    pair2 = {}
    pair3 = {}
    M = 0
    for _ in range(N):
        s = input().rstrip('\n')
        h = 0
        h2 = 0
        h3 = 0
        for i in range(len(s)):
            M += 1
            h = (h*1007 + int(s[i]) + 1) % mod
            pair[h] = (h + 1)%mod if s[i] == '0' else (h-1)%mod
            h2 = (h2 * 2009 + int(s[i]) + 1) % mod2
            pair2[h2] = (h2 + 1)%mod2 if s[i] == '0' else (h2-1)%mod2
            h3 = (h3 * 3001 + int(s[i]) + 1) % mod3
            pair3[h3] = (h3 + 1) % mod3 if s[i] == '0' else (h3 - 1) % mod3
            dic[h] = i+1
            dic2[h2] = i+1
            dic[h3] = i+1
            h_list.append(h)
            h2_list.append(h2)
            h3_list.append(h3)

    g = 0
    seen = defaultdict(int)
    seen2 = defaultdict(int)
    seen3 = defaultdict(int)
    for i in range(M):
        s, s2, s3 = h_list[i], h2_list[i], h3_list[i]
        if seen[s] and seen2[s2] and seen3[s3]:
            continue
        t = pair[s]
        t2 = pair2[s2]
        t3 = pair3[s3]
        if dic[t] == 0 or dic2[t2] == 0 or dic3[t3] == 0:
            p = [dic[s], dic2[s2], dic3[s3]]
            p.sort()
            tmp = L - p[1] + 1
            '''
            if not seen[s]:
                tmp = L - dic[s] + 1
            elif not seen[s2]:
                tmp = L - dic2[s2] + 1
            else:
                tmp = L - dic3[s3] + 1
            '''
            cnt = 0
            while tmp % 2 == 0:
                tmp //= 2
                cnt += 1
            g ^= (2**cnt)
            #print(g, s, s2, t, t2, dic[t], dic2[t2])
        seen[s] = 1
        seen2[s2] = 1
        seen3[s3] = 1

    if g:
        print('Alice')
    else:
        print('Bob')


if __name__ == '__main__':
    main()

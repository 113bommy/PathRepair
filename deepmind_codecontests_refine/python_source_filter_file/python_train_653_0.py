import sys
input = sys.stdin.readline
from collections import Counter
from string import ascii_lowercase

for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()[:-1]
    if n % k:
        print(-1)
        continue
    cnt = Counter(s)
    tot = 0
    for v in cnt.values():
        tot += k - v % k
    if not tot:
        print(s)
        continue
    cand = ascii_lowercase
    flag = 0
    for i in range(n - 1, -1, -1):
        tot -= (k - cnt[s[i]] % k) % k
        cnt[s[i]] -= 1
        tot += (k - cnt[s[i]] % k) % k
        for c in cand[ord(s[i]) - 96:]:
            tmp = tot
            tot -= (k - cnt[c] % k) % k
            cnt[c] += 1
            tot += (k - cnt[c] % k) % k
            if tot <= n - 1 - i:
                ans = s[: i] + c + 'a' * (n - 1 - i - tot)
                for c in cand:
                    ans += c * ((k - cnt[c] % k) % k)
                print(ans)
                flag = 1
                break
            cnt[c] -= 1
            tot = tmp
        if flag: break
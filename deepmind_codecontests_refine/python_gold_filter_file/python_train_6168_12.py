for i in range(int(input())):
    n, k = map(int, input().split())
    if k == 1:
        print(*sorted(input()), sep='')
        continue
    cnt = [0] * 26
    for el in input():
        cnt[ord(el) - ord('a')] += 1
    done = False
    for i in range(26):
        if cnt[i] >= k:
            cnt[i] -= k
            ans = chr(i + ord('a'))
            pp = 0
            for el in cnt:
                if el:
                    pp += 1
            if pp == 1:
                for i in range(26):
                    if cnt[i]:
                        ans += chr(i + ord('a')) * (cnt[i] // k + (cnt[i] % k != 0))
                        print(ans)
                        done = True
                        break
            else:
                for i in range(26):
                    ans += chr(i + ord('a')) * cnt[i]
                print(ans)
                done = True
            break
        elif cnt[i] > 0:
            k -= cnt[i]
            cnt[i] = 0
            break
    if not done:
        for i in range(26):
            if cnt[i] >= k:
                print(chr(i + ord('a')))
                break
            else:
                k -= cnt[i]

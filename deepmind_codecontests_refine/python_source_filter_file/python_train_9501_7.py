# @author 

import sys

class DOmkarAndBedWars:
    def solve(self, tc=0):
        for _ in range(int(input())):
            n = int(input())
            s = list(input().strip())
            ans = 0
            op = {
                'R' : 'L',
                'L' : 'R'
            }
            # for i in range(n):
            #     if s[i] == s[(i - 1) % n] == s[(i - 2) % n]:
            #         if s[(i + 1) % n] == s[i] == s[(i + 2) % n]:
            #             ans += 1
            #             s[i] = op[s[i]]
            # # print(s)
            # for i in range(n):
            #     if s[i] == s[(i - 1) % n] == s[(i - 2) % n]:
            #         ans += 1
            #         if s[(i + 1) % n] != s[i] and s[(i + 2) % n] != s[i]:
            #             s[i - 1] = op[s[i]]
            #         else:
            #             s[i] = op[s[i]]
            # # print(s)
            #
            # print(ans)

            if s == ['R'] * n or s == ['L'] * n:
                print((n + 1) // 3)
                continue

            sizes = []
            l, r = 0, 0
            while s[r] == s[0]:
                r += 1
            while s[l] == s[0]:
                l -= 1

            sizes.append(r - l - 1)
            l = n + l
            cur = r
            while cur <= l:
                while r <= l and s[cur] == s[r]:
                    r += 1
                sizes.append(r - cur)
                cur = r

            # print([length for length in sizes if length >= 3])
            print(sum(length // 3 for length in sizes))

solver = DOmkarAndBedWars()
input = sys.stdin.readline

solver.solve()

def main():
    n = int(input())

    for i in range(n):
        l = int(input())
        arr = list(map(int, input().split()))

        even = odd = 0
        evens = []
        odds = []
        for j in arr:
            if j % 2 == 0:
                even += 1
                evens.append(j)
            else:
                odds.append(j)
                odd += 1

        if abs(odd - even) > 1:
            print(-1)
        else:

            if even < odd:
                pos = 0
                ans = 0
                for p, j in enumerate(arr):
                    if j & 1:
                        ans += abs(p - pos)
                        pos += 2
                print(ans)
            elif even > odd:
                pos = 0
                ans = 0
                for p, j in enumerate(arr):
                    if (j & 1) == 0:
                        ans += abs(p - pos)
                        pos += 2
                print(ans)
            else:
                pos = 0
                ans = 0
                pos2 = 0
                ans2 = 0
                for p, j in enumerate(arr):
                    if (j & 1) == 0:
                        ans += abs(p - pos)
                        pos += 2
                for p, j in enumerate(arr):
                    if (j & 1) == 1:
                        ans2 += abs(p - pos2)
                        pos2 += 2
                print(min(ans2, ans))

main()
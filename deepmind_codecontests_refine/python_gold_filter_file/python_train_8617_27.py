from bisect import bisect_left, bisect_right

N = int(input())
S = list(input())
Q = int(input())

D = {chr(ord('a') + i): [] for i in range(26)}

for i, s in enumerate(S):
    D[s].append(i)

for q in range(Q):
    query = list(input().split())
    if query[0] == '1':
        i, x = int(query[1]), query[2]
        i -= 1
        s = S[i]
        if s == x:
            continue

        D[s].remove(i)
        next_i = bisect_left(D[x], i)
        D[x].insert(next_i, i)
        S[i] = x

    if query[0] == '2':
        l, r = int(query[1]), int(query[2])
        l, r = l - 1, r - 1
        ans = 0
        for i in range(26):
            s = chr(ord('a') + i)

            li = bisect_left(D[s], l)
            ri = bisect_right(D[s], r)

            if ri - li > 0:
                ans += 1

        print(ans)
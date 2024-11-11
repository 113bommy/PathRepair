def max_substring(s, ch, n, k):
    i, j = 0, 0
    cnt = 0
    best = 0
    while j < n:
        if s[j] == ch:
            cnt += 1

        if cnt > k:
            tmp = j - 1 - i
            if tmp > best:
                best = tmp

            while i < j and s[i] != ch:
                i += 1
            i += 1
            cnt -= 1
        j += 1

    tmp = j - i
    if tmp > best:
        best = tmp

    return n if cnt <= k and best == 0 else best


n, k = map(int, input().split())
s = input()

a = max_substring(s, 'a', n, k)
b = max_substring(s, 'b', n, k)

print(a if a > b else b)

def pinguin(n, k):
    if n == k == 1:
        return 'a'
    if n < k or k == -1:
        return -1
    s1 = 'ab' * ((n - k) // 2 + 1)
    if (n + k) % 2 == 1:
        s2 = 'a'
    else:
        s2 = ''
    s3 = ''
    for i in range(2, k):
        s3 += chr(i + ord('a'))
    return s1 + s2 + s3


N, K = [int(j) for j in input().split()]
print(pinguin(N, K))

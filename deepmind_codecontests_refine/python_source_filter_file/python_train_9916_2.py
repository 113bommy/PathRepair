for _ in range(int(input())):
    s = list(input())
    n = len(s)
    ans = n
    o = [0] * n
    z = [0] * n
    print(o)
    print(z)
    count = 1
    i = 1
    while i < n and count < 3:
        if s[i] != s[i-1]:
            count += 1
        i += 1
    if count < 3:
        print(0)
        continue
    for index in range(n):
        if s[index] == '1':
            o[index] += 1
        else:
            z[index] += 1
        if index > 0:
            o[index] += o[index-1]
            z[index] += z[index-1]
    for index in range(n):
        ans = min(ans, min(o[index] + z[n-1] - z[index], z[index] + o[n-1] - o[index]))
    # print(o)
    # print(z)
    print(ans)
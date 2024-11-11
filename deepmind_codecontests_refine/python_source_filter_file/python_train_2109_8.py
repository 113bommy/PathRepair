t = int(input())
for _ in range(t) :
    n = int(input())
    s = input()
    i = -1
    while i + 1 < n and s[i + 1] == '0' :
        i += 1
    j = n
    while j - 1 > 0  and s[j - 1] == '1':
        j -= 1
    if i + 1 == j :
        print(s)
    else :
        print((i + 1) * '0' + '0' + '1' * (n - j))
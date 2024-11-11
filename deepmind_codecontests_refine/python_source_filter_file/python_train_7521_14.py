for cas in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    first = 'a' * a[0] + 'b' * (50 - a[0])
    s = [first, 'a' * 50]
    for i in range(1, n):
        k = a[1]
        x = s[i][:k]
        for j in range(k, 50):
            x += 'b' if  s[i][j] == 'a' else 'a'
        s.append(x)
    for x in s:
        print(x)

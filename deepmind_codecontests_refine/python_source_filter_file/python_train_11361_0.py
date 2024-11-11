t = int(input())
kod = 97

for i in range(t):
    n, k = map(int, input().split())
    s  = ''
    for j in range(n):
        s += chr(j % n + 97)
    print(s)


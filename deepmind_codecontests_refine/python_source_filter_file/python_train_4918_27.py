abc = 'abcdefghijklmnopqrstuvwxwz'
for _ in range(int(input())):
    n, a, b = map(int, input().split())
    s = abc[:b] + abc[b - 1] * (a - b)
    print(s * (n // a) + s[:n % a])

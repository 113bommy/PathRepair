from sys import stdin
input = stdin.buffer.readline

s = '10' * 50

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    if not b:
        print('0' * (a + 1) if a else '1' * (c + 1))
    else:
        print((s[:b - 1][::-1] if b else '') + '0' * (a + 1) + '1' * (c + 1))
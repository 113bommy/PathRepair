from sys import stdin
input = stdin.readline
n, x = map(int, input().split())
x = 1 << len(bin(x)) - 3
a = [i for i in range(1, max(1 << n, x)) if (i >> len(bin(x)) - 3) & 1 == 0] + [0]
b = [a[i] ^ a[i - 1] for i in range(len(a) - 1)]
print(len(b), *b)
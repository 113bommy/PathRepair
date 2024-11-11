from sys import stdin, stdout
n, x = map(int, stdin.readline().split())
s = sum(map(int, stdin.readline().split()))
stdout.write(str((abs(s) + n - 1) // n))

from sys import stdin, stdout
from os import path
if path.exists('inp.txt'):
    stdin = open("inp.txt", "r")
q = int(stdin.readline())
for _ in range(q):
    a, b, c, n = map(int, stdin.readline().split())
    if (n + b + a + c) % 3 != 0:
        stdout.write("NO\n")
    else:
        sum = int((n + a + b + c) / 3)
        if sum < a or sum < b or sum < c:
            stdout.write("NO\n")
        else:
            stdout.write("YES\n")
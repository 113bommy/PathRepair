from sys import stdin, stdout
n = int(stdin.readline())
challengers = set(map(int, stdin.readline().split()))

for i in range(1, n + 10):
    if not i in challengers:
        stdout.write(str(i))
        break

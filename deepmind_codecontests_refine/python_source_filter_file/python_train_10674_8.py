from sys import stdin, stdout
n = int(stdin.readline())
stdout.write(str(n // 7 + max(n % 7, 5) - 5) + ' ' + str(n // 7 + min(2, n % 7)))
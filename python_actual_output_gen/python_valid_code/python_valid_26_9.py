#In the name of Allah

from sys import stdin, stdout
input = stdin.readline




n = int(input())

for i in range(2, 10 ** 6 + 1):
        if n % (i * i) == 0:
                n /= i
stdout.write(str(n))

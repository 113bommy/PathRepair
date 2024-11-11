import sys

n = int(sys.stdin.readline().strip())
m = n // 2 + 1
for i in range (1, m + 1):
    print("1 " + str(i))
for i in range (2, n - m + 2):
    print(str(i) + " " + str(m))
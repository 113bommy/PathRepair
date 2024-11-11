import sys

a = int(input())
for i in range(2, a):
    if a % i == 0:
        print(str(i) + str(a // i))
        sys.exit(0)
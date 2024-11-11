import sys

n = int(input())
a = [int(x) for x in input().split()]

if all(x == 0 for x in a):
    print("NO")
    sys.exit(0)

if sum(a) != 0:
    print("YES\n1\n1", n)
    sys.exit(0)

for i in range(1, n - 1):
    if sum(a[:i]) != 0 and sum(a[i:]) != 0:
        print("YES\n2")
        print(1, i)
        print(i + 1, n)
        sys.exit(0)

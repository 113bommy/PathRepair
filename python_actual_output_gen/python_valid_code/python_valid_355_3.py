t = int(input())
for i in range(t):
    n = int(input())
    a = [int(s) for s in input().split()]
    print(sorted(a)[::-1])
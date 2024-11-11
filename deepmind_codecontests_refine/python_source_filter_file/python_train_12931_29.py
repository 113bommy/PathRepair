m, n = (int(i) for i in input().split())
s = input().split()
t = input().split()

a = int(input())

for i in range(a):
    b = int(input())
    bs = b % len(s) - 1
    bt = b % len(t) - 1
    print(s[bs] + t[bs])


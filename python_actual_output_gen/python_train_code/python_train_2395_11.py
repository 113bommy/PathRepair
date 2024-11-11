from sys import stdin

na, nb = map(int, stdin.readline().split())
k, m = map(int, stdin.readline().split())

a = list(map(int, stdin.readline().split()))
b = list(map(int, stdin.readline().split()))

if a[k - 1] < b[len(b) - m - 1]:
    print ("YES")
else:
    print ("NO")
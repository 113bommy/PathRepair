from sys import stdin
input = stdin.readline
n, q = list(map(int, input().split()))
a = list(map(int, input().split()))
max = 0
t = []
for i in range(1, n):
    if a[i] > a[max]:
        max = i
for _ in range(max):
    t.append([a[0], a[1]])
    if a[0] >= a[1]:
        a.append(a.pop(1))
    else:
        a.append(a.pop(0))
for _ in range(q):
    m = int(input())
    if m > max:
        print(a[0], a[1+(m-1)%(n-1)])
    else:
        print(str(t[m-1][0]), str(t[m-1][1]))
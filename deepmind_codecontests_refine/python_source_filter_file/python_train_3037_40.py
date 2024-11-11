import math
n = int(input())
ls = list(map(int, input().split()))
pref = [0] * n
s = 0
for i in range(n):
    s += ls[i]
    pref[i] = s

for t in range(int(input())):
    a, b = list(map(int, input().split()))
    print( (pref[b-1]-pref[a-1]) // 10)

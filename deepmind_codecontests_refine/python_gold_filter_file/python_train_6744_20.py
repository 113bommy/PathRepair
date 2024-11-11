n = int(input())
l = list(map(int, input().split()))
r = [0]*n
for i in l:
    r[i-1] += 1
for i in r:
    print(i)
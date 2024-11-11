used = [0]*3002
n = int(input())
vals = list(sorted(list(map(int, input().split()))))
for i in range(n):
    used[vals[i]] = 1
for i in range(1, 3002):
    if used[i]==0:
        print(i)
        break

from sys import stdin,stdout
i1 = lambda : int(stdin.readline())
iia = lambda : list(map(int, stdin.readline().split()))
isa = lambda: stdin.readline().split()

n, k = iia()
arr = []
for i in range(n):
    arr.append(iia())
arr.sort(key=lambda x: (-x[0], x[1]))
d = {1: [1]}
rank = count = 1
for i in range(1, n):
    if arr[i] == arr[i - 1]:
        d[rank][0] += 1
        count+=1
    else:
        rank += count
        d[rank] = [1]
        count = 1
old = d[1][0]
for i in sorted(d):
    if i > k:
        print(old)
        break
    old = d[i][0]
else:
    print(old)

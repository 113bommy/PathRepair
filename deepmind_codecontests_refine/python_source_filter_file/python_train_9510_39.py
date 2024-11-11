from sys import stdin

n = int(stdin.readline())
times = list(map(int, stdin.readline().split()))

minTime = min(times)

count = []
for i in range(1, n):
    if times[i] == minTime:
        count.append(i)

if len(count) == 1:
    print(count[0] + 1)
else:
    print('Still Rozdil')
from collections import defaultdict

n = int(input())

arr = [int(i) for i in input().split()]

prefix = [0 for i in range(n)]
segments = defaultdict(list)
prefix[0] = arr[0]
for i in range(1,n):
    prefix[i] = prefix[i - 1] + arr[i]

long = 0
long_i = 0

for i in range(n):
    for j in range(n):
        if j + i > n - 1:
            break
        l, r = i, j + i
        res = prefix[r] - ((prefix[l - 1]) if l != 0 else 0)
        
        if res not in segments:
            segments[res].append(l)
            segments[res].append(r)
        elif r < segments[res][-1]:
            segments[res][-2] = l
            segments[res][-2] = r
        elif segments[res][-1] < l:
            segments[res].append(l)
            segments[res].append(r)
        if len(segments[res]) > long:
            long = len(segments[res])
            long_i = res

print(len(segments[long_i])//2)
for i in range(0,len(segments[long_i]),2):
    print(segments[long_i][i] + 1,segments[long_i][i + 1] + 1)



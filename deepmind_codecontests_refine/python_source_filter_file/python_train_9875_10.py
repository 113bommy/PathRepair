# frequency
from collections import defaultdict
N = int(input())
A = list(map(int, input().split()))
seq = []
freq = [0 for i in range(N+1)]
D = defaultdict(list)
minD = defaultdict(int)
for i, v in enumerate(A):
    D[v].append(i+1)
for key in D.keys():
    minD[key] = min(D[key])
for cnt in D.keys():
    seq.append((cnt, len(D[cnt]), minD[cnt]))
seq.append((0, 0, 0))
seq.sort(key=lambda x: -x[-1])
now_height, now_size, now_min = seq[0]
# howmany,group_size,minimum
for i in range(1, len(seq)):
    freq[now_min] += (now_height-seq[i][0]) * now_size
    now_min = min(now_min, seq[i][2])
    now_size += seq[i][1]
    now_height = seq[i][0]
for i in range(1, N+1):
    print(freq[i])
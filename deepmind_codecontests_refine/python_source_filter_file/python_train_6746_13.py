import bisect
N = int(input())
seq = [-int(input()) for i in range(N)] 
LIS = [seq[0]]
for i in range(1,len(seq)):
    if seq[i] >= LIS[-1]:
        LIS.append(seq[i])
    else:
        LIS[bisect.bisect_left(LIS, seq[i])] = seq[i]
print(len(LIS))
n = int(input())
seq = [2]
for i in range(0,n-1):
    seq.append(seq[i]+1)

print(' '.join(map(str,seq)))
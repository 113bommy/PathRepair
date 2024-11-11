N = int(input())
W = [input() for i in range(N)]
if all(W[i+1][0]==W[i][-1] and W[i] not in W[:i] for i in range(N-1)):
    print('Yes')
else:
    print('No')
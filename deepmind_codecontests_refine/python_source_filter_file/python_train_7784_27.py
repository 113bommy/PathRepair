N, M = map(int, input().split())
piv = N//4+(N%4==3)
pairs = [(str(piv-i), str(piv+1+i)) for i in range(N//4+(N%4==3))]
piv = N - N//4-(N%4==0)
pairs += [(str(piv-1-i), str(piv+1+i)) for i in range(N//4-(N%4==0))]
for pair in pairs[:M]:
    print(' '.join(pair))
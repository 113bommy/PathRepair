N,K=map(int,input().split())

N=N%K

print(min(K,abs(N-K)))
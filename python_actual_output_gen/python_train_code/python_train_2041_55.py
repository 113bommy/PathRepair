N,K=map(int, input().split())
print("YNEOS"[not(K<=N//2+1)::2])
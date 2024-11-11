N,K=map(int, input().split())
print("YNEOS"[not(K*2-1<=N)::2])
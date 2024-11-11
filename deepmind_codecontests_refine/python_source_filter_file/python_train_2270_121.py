N,K=map(int,input().split())
S=input()
print(S[0:K]+S[K].lower()+S[-K:])
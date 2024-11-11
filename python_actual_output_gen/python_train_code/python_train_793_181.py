N,K=(int(i) for i in input().split())
S=input()
print(S[:K]+S[K+1].lower()+S[K+1:])
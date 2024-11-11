A,B,C,K = map(int,input().split())
S = 0
S+=1*min(A,K)
K-=A
K-=B
S-=1*min(C,max(K,0))
print(S)
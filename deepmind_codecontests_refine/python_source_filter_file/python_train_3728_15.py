X,Y,Z,K=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)

K=min(K,3000)

AB=[a+b for a in A for b in B]
AB.sort(reverse=True)

ABC=[ab+c for ab in AB[:K] for c in C]
ABC.sort(reverse=True)

for k in range(K):
	print(ABC[k])

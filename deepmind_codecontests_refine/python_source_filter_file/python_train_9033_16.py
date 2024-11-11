A,B=map(int,input().split())
C=list(map(int,input().split()))
C.sort(reverse=True)
sum(C[B:])
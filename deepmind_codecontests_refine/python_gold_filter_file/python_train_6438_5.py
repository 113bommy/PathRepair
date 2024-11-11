from collections import deque
N,M=list(map(int,input().split()))
N_l=set()
one_l=set()
for i in range(M):
   A,B=list(map(int,input().split()))
   if A == 1:
      one_l.add(B)
   elif B==N:
      N_l.add(A)
if len(N_l & one_l) > 0:
   print("POSSIBLE")
else:
   print("IMPOSSIBLE")

def m(L,R):
 global c;c+=len(L)+len(R)
 T=[]
 for l in L[::-1]:
  while R and R[-1]>l:T+=[R.pop()]
  T+=[l]
 return R+T[::-1]
def d(A):s=len(A)//2;return m(d(A[:s]),d(A[s:])) if len(A)>1 else A
c=0
input()
print(*d(list(map(int,input().split()))))
print(c)

def m(L,R):
 T=[]
 for l in L[::-1]:
  while R and R[-1]>l:T+=[R.pop()]
  T+=[l]
 return R+T[::-1]
def d(A):
 l=len(A);global c;c+=l
 s=l//2;return m(d(A[:s]),d(A[s:]))if l>1 else A
c=-int(input())
print(*d(list(map(int,input().split()))))
print(c)

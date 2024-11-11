def argsort(a):
  ind,_ = zip(*sorted(enumerate(a),key=lambda x:x[1]))
  return ind

def solve(A):
  out = len(A)*2-1
  for i in range(len(A)-2):
    ind = argsort(A[i:i+3])
    if ind in {(0,2,1),(1,2,0),(2,0,1),(1,0,2)} and A[i+1] != A[i] and A[i+1] != A[i+2]:
      out += 1
    else: continue
    if A[i]==A[i+2]: continue
    if i < len(A)-3:
      ind = argsort(A[i:i+4])
      if ind in {(1,3,0,2),(2,3,0,1),(1,0,3,2),(2,0,3,1)} and \
      A[i+3] != [i+1] and A[i+3] != A[i+2]:
        out += 1
  return out

T=int(input())
for t in range(T):
  input()
  *A,=map(int,input().split())
  print(solve(A))
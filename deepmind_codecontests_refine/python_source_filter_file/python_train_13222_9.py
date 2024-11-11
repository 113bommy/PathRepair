def insertionSort(A, n, g):
  ret=0
  for i in range(g,n):
    v = A[i]
    j = i - g
    while j >= 0 and A[j] > v:
      A[j+g] = A[j]
      j = j - g
      ret+=1
      A[j+g] = v
  return ret

n=int(input())
arr=[int(input()) for _ in range(n)]
cnt=0
g=[]
h=1
while h<n:
  g.append(h)
  h=h*3+1
g=sorted(g,reverse=True)
m=len(g)
for i in range(m):
  cnt+=insertionSort(arr, n, g[i])
print(m)
print(' '.join(map(str,g)))
print(cnt)
for i in range(n):
  print(arr[i])

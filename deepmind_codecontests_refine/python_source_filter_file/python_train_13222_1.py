n = int(input())
A = [int(input()) for i in range(n)]

def insertionSort(A, n, g):
 global cnt
 for i in range(g, n):
  v = A[i]
  j = i - g
  while j >= 0 and A[j] > v:
   A[j + g] = A[j]
   j -= g
   cnt +=1
  A[j + g] = v

def shellSort(A, n, m, G):
 A1 = A[:]
 global cnt
 cnt = 0
 for i in range(m):
  insertionSort(A1, n, G[i])
 return A1

def Gmake(n):
 G=[]
 k = 1
 while k < n and len(G) < 100:
  G.append(k)
  k = 3 * k + 1
 G.reverse()
 return G

G = Gmake(n)
A2 = shellSort(A, n, len(G), G)
print(str(len(G)))
print(" ".join(map(str, G)))
print(str(cnt))
for i in A2:
 print(str(i))
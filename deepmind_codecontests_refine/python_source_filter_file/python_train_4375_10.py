def partition(A, p, r):
   x = A[r]
   i = p-1
   for j in range(p,r):
      if A[j] <= x:
         i = i+1
         A[i], A[j] = A[j], A[i]
   A[i+1], A[r] = A[r], A[i+1]
   return i+1

def quickSort(A, p, r):
   if p < r:
      q = partition(A, p, r)
      quickSort(A, q, p-1)
      quickSort(A, q+1, r)

def check(A, s, e):
   for i in range(s,e-1):
      if A[i][1] == A[i+1][1]:
         if A[i][2] > A[i+1][2]:
            return "Not stable"
   return "Stable"

r = int(input())
a = []
for i in range(r):
   c = input().split()
   a.append((c[0],int(c[1]),i))
quickSort(a, 0, r-1)
print(check(a,0,r))
for s,r,d in a:
   print("{} {}".format(s,r))
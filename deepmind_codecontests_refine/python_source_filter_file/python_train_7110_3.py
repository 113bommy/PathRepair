import sys,os,io
input = sys.stdin.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n1, n2, n3, n4 = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
D = list(map(int, input().split()))
from collections import defaultdict
m1 = int(input())
dic1 = defaultdict(lambda: 0)
for i in range(m1):
  x,y = map(int, input().split())
  dic1[(x-1,y-1)] = 1
m2 = int(input())
dic2 = defaultdict(lambda: 0)
for i in range(m2):
  x,y = map(int, input().split())
  dic2[(x-1,y-1)] = 1
m3 = int(input())
dic3 = defaultdict(lambda: 0)
for i in range(m3):
  x,y = map(int, input().split())
  dic3[(x-1,y-1)] = 1
lis1 = []
lis2 = []
lis3 = []
lis4 = []
for i,d in enumerate(D):
  lis4.append((d,i))
lis4.sort()
for j,c in enumerate(C):
  for d,i in lis4:
    if dic3[(j,i)]==0:
      lis3.append((c+d,j))
      break
lis3.sort()
for k,b in enumerate(B):
  for c,j in lis3:
    if dic2[(k,j)]==0:
      lis2.append((b+c,k))
      break
lis2.sort()
for l,a in enumerate(A):
  for b,k in lis2:
    if dic1[(l,k)]==0:
      lis1.append((a+b,l))
      break
if len(lis1):
  print(lis1[0][0])
else:
  print(-1)


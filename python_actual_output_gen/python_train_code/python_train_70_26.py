n = int(input())
L = [int(i) for i in input().split()]
c = sum(int(i) for i in input().split())
C = [int(i) for i in input().split()]
for i in range(len(L)-1):
  if L[i]+1 == L[i+1]:
    c += C[i-1]
print(c)
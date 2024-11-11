n = int(input())
L = [int(i) for i in input().split()]
c = sum(int(i) for i in input().split())
C = [int(i) for i in input().split()]
for i in range(len(L)):
  if L[i] == L[i+1]:
    c += C[i-1]
print(c)
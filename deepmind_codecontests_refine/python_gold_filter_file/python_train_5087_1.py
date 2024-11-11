N = int(input())
a = [int(i) for i in input().split()]
S = 0
for i in range(N):
  if a[a[i]-1] == i+1:
    S += 1
print(S//2)
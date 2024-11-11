N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
allSousa = sum(B)-sum(A)
atob = 0
for a, b in zip(A, B):
  if a < b:
    atob += (b-a)//2+(b-a)%2
if allSousa < atob:
  print("No")
else:
  print("Yes")

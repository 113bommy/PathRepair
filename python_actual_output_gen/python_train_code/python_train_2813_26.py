N=int(input())
L=list(map(int,input().split()))
if N==set(L):
  print("YES")
else:
  print("NO")
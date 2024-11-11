N=int(input())
S=input()
if S[:N//2-1]==S[N//2:]:
  print("Yes")
else:
  print("No")
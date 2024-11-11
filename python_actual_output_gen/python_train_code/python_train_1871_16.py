N=int(input())
S=input()
if S[0:N//2-1]==S[N//2:-1]:
  print("Yes")
else:
  print("No")
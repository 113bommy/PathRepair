SP = input()
T = input()
S = ""

for i in range(len(SP)-len(T)+1):
  cnt = 0
  for j in range(len(T)):
    if SP[i+j] == T[j] or SP[i+j] == "?":
      cnt = cnt +1
  if cnt == len(T):
    S = (SP[:i] + T + SP[i+len(T):]).replace("?","a")
    break
###    
if S == "":
  print("UNRESTORABLE")
else:
  print(S)
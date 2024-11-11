S={c:list(input()) for c in "abc"}
#print(S)
s="a"
while S[s]:
  s=S[s].pop(0)
print(s.upper())
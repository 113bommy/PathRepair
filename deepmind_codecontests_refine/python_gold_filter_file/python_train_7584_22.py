dic_S = {c: list(input()) for c in "abc"}
s = "a"
while dic_S[s]:
  s = dic_S[s].pop(0)
print(s.upper())  
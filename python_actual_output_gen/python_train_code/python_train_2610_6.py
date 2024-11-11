S = {x: list(input()) for x in 'abc'}
s = 'a'
while S[s]:
  s = S[s].pop(0)
print(upper(s))

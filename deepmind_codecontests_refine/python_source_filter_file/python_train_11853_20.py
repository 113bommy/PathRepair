h, w = map(int, input().split())
S = [input() for i in range(h)]
print(S)
print("#"*(w+2))
for s in S:
  print("#"+s+"#")
print("#"*(w+2))
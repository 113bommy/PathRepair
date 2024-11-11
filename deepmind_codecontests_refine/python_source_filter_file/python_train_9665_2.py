n=int(input())
S=set()
for i in range(n):
  S=S^set([input()])
print(len(S))
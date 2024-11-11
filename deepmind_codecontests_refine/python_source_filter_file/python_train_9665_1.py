n=int(input())
S=set()
for i in range(n):
  S=S^set([int(input())])
print(len(S))
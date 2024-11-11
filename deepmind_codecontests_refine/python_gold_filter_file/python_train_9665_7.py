N=int(input())
s=set()
for i in range(N):
  a={input()}
  s^=a
print(len(s))
N=int(input())
s=set()
for i in range(N):
  a=set(input())
  s^=a
print(len(s))
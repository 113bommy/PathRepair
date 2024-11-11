n=int(input())
a=-n
for i in range(n):
  a-=eval(input().replace(" ","-"))
print(a)
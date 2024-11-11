a=int(input())a\
b=input()
c=0
for i in range(a-1):
  if b[i]==b[i+1]:
    c=c+1
print(a-c)
a,b = map(int,input().split())
i = 0
while a+(a-1)*i <b:
  i += 1
print(i+1)
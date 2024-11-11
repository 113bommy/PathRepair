N = int(input())
c =0
for i in range(1,N+1):
  if len(str(i)) % 2 == 1:
    c+=1
print(c)

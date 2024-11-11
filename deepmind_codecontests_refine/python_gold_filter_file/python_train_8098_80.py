a = input()
b = 0
for i in range(1,int(a)+1):
  if len(str(i))%2 ==1:
    b+=1
print(b)
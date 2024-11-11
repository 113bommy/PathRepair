num = int(input())
i = 1
y=0
while i+num < 9000:
  if len(set(str(num+i))) == 4:
    y = num+i
    break
  i+=1

print(y)
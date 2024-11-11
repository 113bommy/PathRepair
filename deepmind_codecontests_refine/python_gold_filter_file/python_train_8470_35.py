num = int(input())
i = 1
y=0
while i+num < 10000:
  if len(set(str(num+i))) == 4:
    y = num+i
    break
  i+=1

print(y)
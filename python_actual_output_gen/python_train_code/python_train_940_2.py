a = input()
num=0
b=[]
for i in a:
  if a[i] in 'ATGC':
    num+=1
  else:
    b.append(num)
    num=0
print(max(b))
    
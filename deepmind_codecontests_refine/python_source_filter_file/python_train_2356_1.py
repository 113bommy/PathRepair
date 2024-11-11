input()
data = [int(x) for x in input().split()]
al=0
for x in range(len(data)):
  if x==0 or x==len(data)-1:
    continue
  if (data[x]<data[x+1] and data[x]<data[x-1]) or (data[x]>data[x+1] and data[x]>data[x-1]):
    al+=x-1
print(al)
n=int(input())
flag=0
for i in range(2,10):
  if n%i == 0 and n/i<10:
    flag = 1
print("YNeos"[flag!=1::2])

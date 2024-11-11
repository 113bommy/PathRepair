x = int(input())
k = 1
while (x*k)%360 != 0:
  k+=1
print(k)
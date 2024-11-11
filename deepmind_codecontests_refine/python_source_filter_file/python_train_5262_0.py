y=int(input())
leap=(y%100!=0 and y%4==0) or y%400==0
m=0
for j in range(y,10**6):
  if (j%100!=0 and j%4==0) or j%400==0:
    m+=2
  else:
    m+=1
  if m%7==0 and (leap==((j+1)%100!=0 and (j+1)%4==0) or (j+1)%400==0):
    print(j+1)
    exit()
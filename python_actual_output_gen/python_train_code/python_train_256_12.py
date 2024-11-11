n=int(input())
l=list(map(int,input().split()))
count2=0
count4=0
for i in range(n):
  if l[i]%4==0:
    count4+=1
  elif l[i]%2==0:
    count2+=1
if count4*2+count2>n or count4*2+1>n:
  print("Yes")
else:
  print("No")

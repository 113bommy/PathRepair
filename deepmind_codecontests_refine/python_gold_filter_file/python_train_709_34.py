n=int(input())
a=list(map(int,input().split()))
four=0
two=0

for i in range(n):
  if a[i]%4==0:
    four+=1
  elif a[i]%2==0:
    two+=1
one=n-two-four
if one>=four+2 or\
one==four+1 and two>=1:
  print("No")
else:       
  print("Yes")
  
x=int(input())
s=''
if x%2==0:
 for i in range(x//2):
  s=s+'1'
 print(s)
if x%2==1:
 for i in range(x//2-1):
  s=s+'1'
 s=s+'7'
 print(s)
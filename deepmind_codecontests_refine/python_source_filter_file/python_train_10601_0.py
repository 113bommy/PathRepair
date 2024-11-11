x,y=map(int,input().split())
n=y//x
ct=0
while n>1:
  ct+=1
  n//=2
print(ct)
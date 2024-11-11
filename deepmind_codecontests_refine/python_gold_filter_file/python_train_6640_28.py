n=input()
s=list(map(int,input().split()))
for i in s:
  if i%2==0:
    if i%3>0 and i%5>0:
      n=0
print(["APPROVED","DENIED"][n==0])
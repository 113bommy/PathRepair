n=int(input())
a=11
for i in range(1,int(n**0.5)):
  if n%i==0:
    a=min(a,max(len(str(i)),len(str(n//i))))
print(a)
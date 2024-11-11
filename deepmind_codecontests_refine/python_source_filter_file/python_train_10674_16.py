n=int(input())
if n%7==6:k=1
else:k=0
p=n//7+k
if n%7==1:k1=1
elif n%7==2:k1=2
else:k1=0
q=n//7+k1
print(p,q)
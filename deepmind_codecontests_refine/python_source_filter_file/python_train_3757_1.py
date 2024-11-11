p=1;a=[]
n=int(input());s=n**.5
while n%2==0 and n>3:a+=[2];n//=2
d=3
while s>d and n>d:
 if n%d==0:a+=[d];n//=d
 else:d+=2
a+=[n]
for f in set(a):
 p*=f**a.count(f)*(1-1/f)
print(int(p)

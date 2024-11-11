n,a=int(input()),2
for i in range(2,int(n**.5)+1):
  a+=-~(~-n//i>i)*(~-n%i<1)
  if n%i<1:
    m=n
    while m%i<1:m//=i
    a+=m%i<2
print(a)
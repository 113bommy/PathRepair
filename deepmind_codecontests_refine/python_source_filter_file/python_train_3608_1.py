n=int(input())
a=list(map(int,input().split()))
suma=sum(a)
suma=int(suma/2)
i=0
j=-1
while not i>=suma:
  j=j+1
  i=i+a[j]
print(j+1)
  
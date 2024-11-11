n=int(input())
a="zabcdefghijklmnopqrstuvwxy"
b=""
i=1
while n/26>0:
  b=a[n%26]+b
  n=n//26
print(b)

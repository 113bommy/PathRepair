a=input()
b=input()
i=len(a)
j=len(b)
k=i+j
while ((a[i-1]==b[i-j]) and (i>0) and (j>0)):
    i=i-1
    j=j-1
    k=k-2
print(k)
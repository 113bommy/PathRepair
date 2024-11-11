a=input()
a=a.split(' ')
b=int(a[0])
c=int(a[1])
for i in range(c):
    if b%10>0:
        b-=1
    if b%10==0:
        b=b//10
print(b)
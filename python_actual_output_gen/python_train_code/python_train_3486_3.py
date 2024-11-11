n=int(input())
a=input()
b=n//2
c=n-2*b
b-=c
d=''
for i in range(b):
    d+=a[i*2:i*2+2]
    if i!=b-1:
        d+='-'
if b>0:
    d+='-'
for i in range(c):
    d+=a[2*b+3*i:2*b+3*i+3]
    if i!=c-1:
        d+='-'
print(d)
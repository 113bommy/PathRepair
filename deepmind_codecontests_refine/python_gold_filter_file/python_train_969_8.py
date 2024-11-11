a=int(input())
ch=input()
l=ch.split()
for i in range(len(l)):
    l[i]=int(l[i])
max=l[0]
min=l[0]
s=0
for i in range(1,a):
    if l[i]<min:
        s=s+1
        min=l[i]
    if max<l[i]:
        s=s+1
        max=l[i]
print(s)


n=int(input())
x=input()
h=0
a=0
t=0
r=0
i=0
l=x.split(sep=" ")
for i in range (len(l)-1):
    if l[i]=='1':
        t+=1
print (t)
for i in range (len(l)-1):
    if l[i+1]=='1':
        s=len(l[a:i+1])
        a=i+1
        print(s, end=" ")
if l[-1]!='1':
    s=len(l[a:-1])
    print(s+1, end=" ")
if l[-1]=='1':
    s=1
    print(s, end=" ")


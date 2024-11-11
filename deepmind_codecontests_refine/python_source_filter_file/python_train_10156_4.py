import sys
input=sys.stdin.readline

a=input()
a="a"+a+"a"
a=list(a)
b=[]
for i in range(len(a)):
    if a[i]=="a":
        b.append(i)
e=0
for i in range(len(b)-1):
    if b[i]+1!=b[i+1]:
        e=1
        f=b[i]
        g=b[i+1]
        break
if e==0:
    a[-2]="z"
    print("".join(a[1:-1]))
else:
    for i in range(f+1,g):
        a[i]=chr(ord(a[i])-1)
    print("".join(a[1:-1]))
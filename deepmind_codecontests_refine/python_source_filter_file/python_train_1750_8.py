h,w,n=[int(j) for j in input().split()]
R,C=[int(j) for j in input().split()]
s=input()
t=input()

#LR
x=C
l,r=1,w
for i in range(n)[::-1]:
    if t[i]=="R":
        l-=1
    elif t[i]=="L":
        r+=1
    if l==0:
        l=1
    if r>w:
        r=w
    if s[i]=="R":
        r-=1
    elif s[i]=="L":
        l+=1
    if  l>r:
        print("NO")
        exit()
if not l<=x<=r:
    print("NO")
    exit()
#UD
x=R
l,r=1,h
for i in range(n)[::-1]:
    if t[i]=="U":
        l-=1
    elif t[i]=="D":
        r+=1
    if l==0:
        l=1
    if r>h:
        r=h
    if s[i]=="U":
        r-=1
    elif s[i]=="D":
        l+=1
    if l>r:
        print("NO")
        exit()
if not l<=x<=r:
    print("NO")
    exit()
print("YES")
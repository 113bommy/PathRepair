# cook your dish here
f=1
l=[]
for _ in range(int(input())):
    s = input().split("|")
    if f==1:
        if s[0]=="OO":
            s[0]="++"
            f=0
        elif s[1]=="OO":
            s[1]="++"
            f=0
    l.append("|".join(s))
    
if f==1:
    print("NO")
else:
    print("YES")
for i in l:
    print(i)
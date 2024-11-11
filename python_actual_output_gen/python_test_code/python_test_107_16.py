a=int(input())
b=input()
c=[]
for i in range(a):
    if i==0:
        if b[i]=="x":
            c.append(1)
        else:
            c.append(0)
    else:
        if b[i]=="x":
            c[-1]+=1
        elif b[i]!="x" and b[i-1]=="x":
            c.append(0)
if c[-1]==0:
    c.pop(-1)
print(c)
ans=0
for i in range(len(c)):
    if c[i]>=2:
        ans+=(c[i]-2)
print(ans)
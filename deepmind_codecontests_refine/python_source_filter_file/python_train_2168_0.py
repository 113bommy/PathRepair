s=list(input())
t=list(input())
ss=len(set(s))
tt=len(set(t))

l=[]
for i,j in zip(s,t):
    l.append(i+j)
print(l)
if len(set(l)) == ss == tt:
    print("Yes")
else:
    print("No")

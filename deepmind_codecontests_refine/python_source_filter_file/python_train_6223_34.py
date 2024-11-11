s=input()
t=input()
L=len(s)
l=len(t)
X=[]
for i in range(L-l):
    x=0
    for j in range(l):
        if s[i+j]!=t[j]:
            x+=1
    X.append(x)
print(min(X))
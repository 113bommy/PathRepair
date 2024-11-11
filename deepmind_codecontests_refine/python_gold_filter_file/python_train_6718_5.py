f,I,t=input().split()
f=int(f)
I=int(I)
t=int(t)
s=[]
a=0
#kitten
for i in range(f):
    s.append(input())
for i in range(I):
    x=0
    for j in range(f):
        if s[j][i]=='Y':
            x=x+1
    if x>=t:a=a+1
print(a);

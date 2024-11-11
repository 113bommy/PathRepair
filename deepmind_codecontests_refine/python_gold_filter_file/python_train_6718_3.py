'kitten'
f,l,t=map(int,input().split())
s=[input() for _ in range(f)]
a=0
for j in range(l):
    c=0
    for i in range(f):
        c+=s[i][j]=='Y';
    a+=c>=t
print(a)

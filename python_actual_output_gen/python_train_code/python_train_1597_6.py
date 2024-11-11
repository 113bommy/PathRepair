sb=input().split()
s1=input().split()
s2=input().split()
w=int(sb[0])
h1=int(s1[1])
h2=int(s2[1])
w1=int(s1[0])
w2=int(s2[0])
for i in range(int(sb[1]),0,-1):
    if w<0:
        w=0
    w=w+i
    if i==h2:
        w=w-w2
    if i==h1:
        w=w-w1
print(w)
t=int(input())
ss=0
d=[]

for i in range(t):
    s,a,b,c=map(int,input().split())
    ss+=s//c//a*b+s
    d.append(ss)
    ss=0
for i in d:
    print(i)
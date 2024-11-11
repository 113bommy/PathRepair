n=int(input())
s=input()
a=["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]
b=[1]*8;
t=0
for i in s :
    for j in range(0,8) :
        if (len(a[j])!=len(s))or(len(a[j])>t and a[j][t]!=i and i!='.') :
            b[j]=0
    t=t+1
k=0
for k in range(0,8):
    if b[k]==1:
        print(a[k])
        
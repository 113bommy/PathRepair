# cook your dish here
n=int(input())
a=input()
b=input()
zc,oc=0,0
zs,os=0,0
for i in range(n):
    if a[i]=='0':
        zc+=1
        if b[i]=='0':
            zs+=1
    else:
        oc+=1
        if b[i]=='0':
            os+=1
print((zc*os)+(zs*oc)-zs)
            
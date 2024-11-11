n,k=map(int,input().split())
string=str(input())
a=0
b=0
c=0
d=0
for i in range (n):
    if string[i]=='a':
        a+=1
    else:
        b+=1
    if min(a,b)>k:
        if string[c]=='a':
            a-=1
        else:
            b-=1
        c+=1

    else:
        d+=1
print(d)
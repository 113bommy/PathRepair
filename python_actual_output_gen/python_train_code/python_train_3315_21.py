n=int(input())
l=list(map(int,input().split()))
o=0
e=0
for i in l:
    if(i&1):
        o+=1
    else:
        e+=1
if(e==1):
    for i in range(n):
        if(l[i]&1!=0):
            print(i)
            break
else:
    for i in range(n):
        if(l[i]&1):
            print(i)
            break
import os,io
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n = int(input())
s = input()
t = input()
s1 = 0
t1 = 0
if s==t:
    print(0)
else:
    for i in range(n):
        if s[i]=='1':
            s1+=1
        if t[i]=='1':
            t1+=1
    if s1 != t1:
        print(-1)
    else:
        stype1 = 0
        stype2 = 0
        for i in range(n):
            if s[i]=='1' and t[i]=='0':
                stype1+=1
                stype2=max(0,stype2-1)
            elif s[i]=='0' and t[i]=='1':
                stype2+=1
                stype1=max(0,stype1-1)
        print(stype1+stype2)
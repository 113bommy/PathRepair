s=input()
v=0;h=0
for i in s:
    if i=='0':
        if v==0:
            print(1,1)
            v+=1
        else:
            print(3,1)
            v=0
    else:
        print((h)%4+1,2)
        h+=1
            
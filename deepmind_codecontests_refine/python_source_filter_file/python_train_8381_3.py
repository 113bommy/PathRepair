s  = input()
n1,n2,n4,c4 = 0,0,0,0
for i in range(len(s)):
    r = int(s[i])%4
    if r==1 or r==3:
        n1,n2,n4 = i+1,0,0
    elif r==2:
        n1,n2,n4 = 0,(n2+1),n1
    else:
        n1,n2,n4 = 0,n1,(n2+n4+1)
    c4 += n4
print(c4)

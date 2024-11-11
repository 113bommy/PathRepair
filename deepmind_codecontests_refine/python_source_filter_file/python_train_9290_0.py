t=int(input())
a1=[]
a2=[]
b1=[]
b2=[]
for i in range(t):
    ab1=input().split()
    a1.append(int(ab1[0]))
    b1.append(int(ab1[1]))
    ab2=input().split()
    a2.append(int(ab2[0]))
    b2.append(int(ab2[1]))
    pass
for i in range(t):
    mess="yes"
    if a1[i]<b1[i]:
        lo1=b1[i]
        la1=a1[i]
    else:
        la1=b1[i]
        lo1=a1[i]
    if a2[i]<b2[i]:
        lo2=b2[i]
        la2=a2[i]
    else:
        la2=b2[i]
        lo2=a2[i]
    if lo1!=lo2:
        mess="no"
    if la1+la2==lo1:
        mess="yes"
    print(mess)

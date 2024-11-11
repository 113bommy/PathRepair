#dice3
def r(D,s):
    if s==0:
        t=D[0]
        D[0]=D[1]
        D[1]=D[5]
        D[5]=D[4]
        D[4]=t
    elif s==2:
        t=D[0]
        D[0]=D[4]
        D[4]=D[5]
        D[5]=D[1]
        D[1]=t        
    elif s==3:
        t=D[0]
        D[0]=D[3]
        D[3]=D[5]
        D[5]=D[2]
        D[2]=t        
    elif s==1:
        t=D[0]
        D[0]=D[2]
        D[2]=D[5]
        D[5]=D[3]
        D[3]=t
    elif s==4:
        D=r(r(D,1),1)
    return D
def ch(C,D):
    k=0
    while k<6 and C[k]==D[k]:
        k+=1
    if k==6:
        return 1
    else:
        return 0
C=[int(i) for i in input().split()]
D=[int(i) for i in input().split()]
nd=0
if ch(C,D)==1:
    nd=1
i=0
while i<4 and nd==0:
    D=r(D,i)
    j=i+1
    j%=4
    k=0
    if ch(C,D)==1:
        nd=1
 #   if i==0:
    #    print(D)
    while k<3 and nd==0:
        D=r(D,j)
        if ch(C,D)==1:
            nd=1
        k+=1
  #      if i==0:
        #    print(D)
    D=r(D,j)
 #   if i==0:
   #     print(D)
    m=i+2
    m%=4
 #   if i==0:
    #    print(m)    
    D=r(D,m)
 #   if i==0:
 #       print(D)
    i+=1
i=0
while nd==0 and i<4:
    D=r(D,0)
    D=r(D,1)
    D=r(D,0)
    if ch(C,D)==1:
        nd=1
    D=r(r(D,0),0)
    if ch(C,D)==1:
        nd=1
    i+=1
if nd==1:
    p="Yes"
else:
    p="No"
print(p)
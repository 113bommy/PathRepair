n=int(input())
s=list(input())
a1=[]
a2=[]
a3=[]
a4=[]
a5=[]
a6=[]
for each in range(len(s)):
    if each%3==0:
        a1.append('R')
        a2.append('G')
        a3.append('B')
        a4.append('R')
        a5.append('B')
        a6.append('G')
    elif each%3==1:
        a1.append('G')
        a2.append('B')
        a3.append('R')
        a4.append('B')
        a5.append('G')
        a6.append('R')
    else:
        a1.append('B')
        a2.append('R')
        a3.append('G')
        a4.append('G')
        a5.append('R')
        a6.append('B')
        
c1,c2,c3,c4,c5,c6=0,0,0,0,0,0
for num in range(len(s)):
    if s[num]==a1[num]:
        c1+=1
    if s[num]==a2[num]:
        c2+=1
    if s[num]==a3[num]:
        c3+=1
    if s[num]==a4[num]:
        c4+=1
    if s[num]==a5[num]:
        c5+=1
    if s[num]==a6[num]:
        c6+=1
        
if c1==max(c1,c2,c3,c4,c5,c6):
    print(len(s)-c1)
    for x in a1:
        print(x, end = '')
elif c2==max(c1,c2,c3,c4,c5,c6):
    print(len(s)-c2)
    for x in a2:
        print(x, end = '')
elif c3==max(c1,c2,c3,c4,c5,c6):
    print(len(s)-c3)
    for x in a3:
        print(x, end = '')
elif c4==max(c1,c2,c3,c4,c5,c6):
    print(len(s)-c4)
    for x in a4:
        print(x, end = '')
elif c4==max(c1,c2,c3,c4,c5,c6):
    print(len(s)-c5)
    for x in a5:
        print(x, end = '')
else:
    print(len(s)-c6)
    for x in a6:
        print(x, end = '')




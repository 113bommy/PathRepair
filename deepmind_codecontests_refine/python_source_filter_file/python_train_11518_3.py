from sys import stdin
s=list(map(int,stdin.readline().strip().split()))
l1=[s[0],s[2],s[4],s[6],s[8],s[10],s[-3],s[-1]]
l2=[s[1],s[3],s[5],s[7],s[9],s[11],s[-4],s[-2]]
l3=[ s[12],s[13],s[4],s[5],s[16],s[17],s[20],s[21]]
l4=[s[14],s[15],s[6],s[7],s[18],s[19],s[22],s[23]]
l5=[s[0],s[1],s[17],s[19],s[11],s[10],s[14],s[12]]
l6=[s[2],s[3],s[16],s[18],s[9],s[8],s[15],s[13]]
t1=True
t12=True
t2=False
t32=True
t3=True
t4=False
t5=True
t52=True
t6=False
for i in range(2,8+2):
    if l1[i%8]!=l2[i-2]:
        t1=False
for i in range(6,8+6):
    if l1[i%8]!=l2[i-6]:
        t12=False
if l3[0]==l4[0] and l3[1]==l4[1] and l3[0]==l3[1] and  l3[4]==l4[4] and  l3[5]==l4[5] and l3[4]==l3[5]:
    t2=True
for i in range(2,8+2):
    if l3[i%8]!=l4[i-2]:
        t3=False
for i in range(6,8+6):
    if l3[i%8]!=l4[i-6]:
        t32=False
if l1[0]==l2[0] and l1[1]==l2[1] and l1[0]==l1[1] and  l1[4]==l2[4] and  l1[5]==l2[5] and l1[4]==l1[5]:
    t2=True
for i in range(2,8+2):
    if l5[i%8]!=l6[i-2]:
        t5=False
for i in range(6,8+6):
    if l5[i%8]!=l6[i-6]:
        t52=False
if l1[2]==l2[2] and l1[3]==l2[3] and l1[2]==l1[3] and  l1[6]==l2[6] and  l1[7]==l2[7] and l1[6]==l1[7]:
    t6=True
t3=t3 or t32
t1=t1 or t12
t5=t5 or t52
if ( t1 and t2 ) or (t3 and t4) or( t5 and t6):
    print("YES")
else:
    print("NO")

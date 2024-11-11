import math
k =input().split(' ')
q = int(input())
lis=[]
# for _ in range(q):
#     lis.append([])
for oo in range(q):
    lis.append(input())
#print(lis)

n=int(k[0])
d=int(k[1])

x1=0
y1=d
x2=d
y2=0
x3=n
y3=n-d
x4=n-d
y4=n


a=((x1-x2)**2+(y1-y2)**2)**0.5
b=((x2-x3)**2+(y2-y3)**2)**0.5
c=((x3-x4)**2+(y3-y4)**2)**0.5
d=((x4-x1)**2+(y4-y1)**2)**0.5
s=(a*b)


for pp in range(q):

    x5=int(lis[pp].split(' ')[0])
    y5=int(lis[pp].split(' ')[1])



    r1=((x1-x5)**2+(y1-y5)**2)**0.5
    r2=((x2-x5)**2+(y2-y5)**2)**0.5
    r3=((x3-x5)**2+(y3-y5)**2)**0.5
    r4=((x4-x5)**2+(y4-y5)**2)**0.5

    p1=(a+r1+r2)/2
    s1=(p1*(p1-a)*(p1-r1)*(p1-r2))**0.5

    p2=(b+r2+r3)/2
    s2=(p2*(p2-b)*(p2-r3)*(p2-r2))**0.5

    p3=(c+r3+r4)/2
    s3=(p3*(p3-c)*(p3-r3)*(p3-r4))**0.5

    p4=(d+r4+r1)/2
    s4=(p4*(p4-d)*(p4-r1)*(p4-r4))**0.5



    #print(s, s1, s2, s3, s4, s1+s2+s3+s4,p1,p2,p3,p4)
    #print(r1,r2,r3,r4)
    #print(abs(s - (s1+s2+s3+s4)))
    try:
        if abs(s - (s1+s2+s3+s4))<0.01:
                            print('YES')
        else:
            print("NO")
    except:
        print("NO")



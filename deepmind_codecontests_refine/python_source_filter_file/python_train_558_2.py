a=int(input())
b=list(map(int,input().split()))
x=[]
c=0
if(0 in b):
    x.append('0')
    b.remove(0)
if(100 in b):
    x.append('100')
    b.remove(100)
for _ in b:
    if(0<_<10):
        x.append(str(_))
        # c+=1
        break
for _ in b:
    if(_%10==0):
        x.append(str(_))
        c+=1
        break
if(c==0):
    for _ in b:
        if(10<_<100 and _%100!=0):
            x.append(str(_))
            break

print(len(x))
print(' '.join(x))

# CodeBy: RAHUL MAHAJAN
# A2OJ: rahulmahajan
# CC: anonymous0201
# CF: rahulmahajan
# CSES: rahulmahajan
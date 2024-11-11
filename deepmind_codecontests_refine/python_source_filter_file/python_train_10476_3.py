a=input()


aa=[]
ab=[]
q1=0
q=0
for i in range(len(a)):
    if a[i]=='Q':
        q+=1
    elif a[i]=='A':
        aa.append(q)
    if a[(i+1)*(-1)]=='Q':
        q1+=1
    elif a[(i+1)*(-1)]=='A':
        ab.append(q1)
f=0
#print(aa,ab)
for i in range(len(aa)):
    f=f+max(aa[i],ab[(i+1)*(-1)])
print(f)

a=(input())
a=list(a)
count0=1
count1=1
for i in range(len(a)):
    if i<len(a)-1:
        if a[i]=='1' and a[i+1]=='1':
            count1+=1
        elif a[i]=='1' and a[i+1]!='1' and count1<7:
            count1=1
    if count1==7:
        break
for i in range(len(a)):
    if i<len(a)-1:
        if a[i]=='0' and a[i+1]=='0':
            count0+=1
        elif a[i]=='0' and a[i+1]!='0' and count0<7:
            count0=1
        if count0==7:
            break
if count1>=7 or count0>=7:
    print("YES")
else:
    print("NO")
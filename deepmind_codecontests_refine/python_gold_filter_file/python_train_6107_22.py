a=input()
prev=a[0]
count=1
check=0
for i in range (1,len(a)):
    if prev==a[i]:
        count+=1
    elif prev!=a[i]:
        count=1
        prev=a[i]
    if count>=7:
        print ("YES")
        check+=1
        break
if check==0:
    print ("NO")
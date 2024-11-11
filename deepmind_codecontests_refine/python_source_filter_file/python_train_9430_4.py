x={'a','e','i','o','u'}
count1=0
count2=0
count3=0
a=input()
b=input()            
c=input()
for i in range(len(a)):
    if a[i] in x:
        count1 +=1
for i in range(len(b)):
    if b[i] in x:
        count2 +=1        
for i in range(len(c)):
    if c[i] in x:
        count3 +=1        
if count1==5 and count2==7 and count3==5:
    print('Yes')
else:
    print('No')
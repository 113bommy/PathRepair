a=input()
b=[]
c=0
for i in range(len(a)):
    if a[i] not in b:
        c+=1
        b+=a[i]
if c%2==1:
    print('IGNORE HIM')
else:
    print('CHAT WITH HER')
a,b=map(int,input().split())
i=1
r=1
while i>0:
    if i%2==0:
        b=b-i
    else:
        a=a-i
    if a==0 or b==0:
        break
    i=i+1
if a==0:
    print('Valera')
else:
    print('Vladik')
    
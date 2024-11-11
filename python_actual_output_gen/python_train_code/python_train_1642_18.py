n=(input('enter')).lower()
l='abcdefghijklmnopqrstuvwxyz'
temp=''
v='aeiouy'
for i in n:
    if(i in l):
        temp+=i
if(temp[-1] in v):
    print("YES")
else:
    print("NO")


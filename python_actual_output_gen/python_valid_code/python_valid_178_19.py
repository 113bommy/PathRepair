x= int (input())
c= input()
d=c.lower()
print(d)
a="abcdefghijklmnopqrstuvwxyz"
t=0
for i in a:
    if i not in d:
        t=1
if(t==1):
    print("NO")
else:
    print("YES")
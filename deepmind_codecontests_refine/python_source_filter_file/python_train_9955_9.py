s=input()
z=['Danil','Olya','Slava','Nikita']
tot=0
for i in z:
    if i in s:
        tot=s.count(i)         
if tot==1:
    print("YES")
else:
    print("NO")

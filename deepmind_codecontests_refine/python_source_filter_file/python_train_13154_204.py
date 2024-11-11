l=input()
p=[]
for i in l:
    if i not in l:
        p.append(i)
z=len(p)

if z%2 == 0:
    print ("CHAT WITH HER!")
else:
    print ("IGNORE HIM!")

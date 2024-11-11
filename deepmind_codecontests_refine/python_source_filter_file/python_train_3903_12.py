a=input()
a=a.replace('4','1')
a=a.replace('7','2')
tot=0
for i in a:
    tot=int(i)+tot**2
print(tot)

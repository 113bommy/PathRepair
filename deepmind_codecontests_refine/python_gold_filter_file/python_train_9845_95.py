n=int(input())
m=input()
t1=['Anton']
t2=['Danik']
t3=['Friendship']

if m.count('A')>m.count('D'):
    for arip in t1:
        print(arip,end='')
elif m.count('A')<m.count('D'):
    for arip in t2:
        print(arip,end='')
else:
    for arip in t3:
        print(arip,end='')
    

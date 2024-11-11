n = int(input())

c = 0

while n:
    if n>=100:
        n-=100
        c+=1

    if n>=20:
        n-=20
        c+=1

    if n>=10:
        n-=10
        c+=1

    if n>=5:
        n-=5
        c+=1

    if n>=1:
        n-=1
        c+=1
        
print(c)
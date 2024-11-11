import fractions 
n=int(input())
for _ in range(n):
    a,b,c,d=map(int,input().split())
    if d<b:
        print("No")
        continue
    elif a<b:
        print("No")
        continue
    elif c<=b:
        print("Yes")
        continue
    g=fractions.gcd(b,d)
    h=((b-1-a%b)//g)*g
    if a%b+h>c:
        print("No")
        continue
    print("Yes")
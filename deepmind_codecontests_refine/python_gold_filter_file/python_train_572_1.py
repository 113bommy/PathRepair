a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)
possible = False
for i in range(100000):
    if((a*i)>c):
        break
    x = (c-(a*i))%b
    if(x==0):
        possible = True
        break
if(possible):
    print("YES")
else:
    print("NO")
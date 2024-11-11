def gcd(a,b) :
    if a%b==0 :
        return b
    else :
        return gcd(b,a%b)
n=int(input())
for x in range(n) :
    a=int(input())
    b=180//gcd(a,180)
    if b<=3 :
        print(-1)
        continue
    if abs(a//(180//b)-b)==1 :
        print(b*2)
    else :
        print(b)

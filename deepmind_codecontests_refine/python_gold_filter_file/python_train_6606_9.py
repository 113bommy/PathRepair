import math
s1=input()
s2=input()
c1=s1.count("+")
c2=s1.count("-")
c3=s2.count("+")
c4=s2.count("-")
ans=0
c=s2.count("?")
if(c==0 and c2==c4 and c3==c1):
    ans=1/1
elif c==0 and (c3!=c1 or c2!=c4):
    ans=0/1
elif(c3>c1 or c4>c2):
    ans=0/1
else:
    d1=c2-c4
    d2=c1-c3
    d=d1+d2
    ans=math.factorial(d)/(math.factorial(d1)*math.factorial(d2))
    ans/=(pow(2,c))
print ("{0:.12f}".format(ans))


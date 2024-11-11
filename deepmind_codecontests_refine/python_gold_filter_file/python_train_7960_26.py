digit=int(input())
number=int(input())
newNumber=0
while number>0:
    x=number%10
    number=number//10
    if x!=0 and x!=1:
        if x==2 or x==3 or x==5 or x==7:
            newNumber=newNumber*10+x
        elif x==4:
            newNumber=newNumber*1000+223
        elif x==6:
            newNumber=newNumber*100+53
        elif x==8:
            newNumber=newNumber*10000+2227
        elif x==9:
            newNumber=newNumber*10000+3327
a=list(str(newNumber))
a.sort()
a.reverse()
l=len(a)
N=0
for i in range(0,l):
    N=N*10+int(a[i])
print(N)
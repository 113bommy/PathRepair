a = int(input())
c=a
b=len(str(a))
i=0
while a%10==0:
    a=a//10
    i+=1
if a>0 and a<=9:
    print(10**i)
else:
    print(10**(b-1)-c%(10**(b-1)))
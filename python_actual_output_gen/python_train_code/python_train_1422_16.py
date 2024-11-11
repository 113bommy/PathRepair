n=int(input())
x=len(str(n))
sum=0
sum+=x*(n-(10**(x-1))+1)
x-=1
while x>0:
    sum+=9*(10**(x-1))
    x-=1
print(sum)
n=abs(int(input()))
i=0
while n>0 or n%2==1:
    i+=1
    n-=i
print(i)

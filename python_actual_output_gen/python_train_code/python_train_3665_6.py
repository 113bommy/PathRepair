n=int(input())
first=(n//7)*2
second=(n//7)*2
if n==6:
    first+=1
if n%7>=2:
    second+=2
elif n%7==1:
    second+=1
print(first,second)
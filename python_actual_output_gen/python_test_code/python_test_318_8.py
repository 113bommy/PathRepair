x=int(input())
i=100
c=0
while i<=x:
    i=i+(i//100)
    c=c+1
print(c)
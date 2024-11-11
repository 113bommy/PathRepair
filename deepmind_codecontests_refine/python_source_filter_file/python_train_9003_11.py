n = int(input())
c = 0
while(n>0):
    if(n%2==1):
        c+=1
    n/=2
print(c)
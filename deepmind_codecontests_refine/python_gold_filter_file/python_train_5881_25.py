n=int(input())
n1,n2=int(input()),int(input())
c=0
while n1>0 or n2>0:
    r1=n1%10
    r2=n2%10
    n1=n1//10
    n2=n2//10
    #print(abs(r1-r2),(9-max(r1,r2))+min(r1,r2)+1)
    c+=min(abs(r1-r2),(9-max(r1,r2))+min(r1,r2)+1)
print(c)
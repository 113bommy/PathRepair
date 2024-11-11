
list1= input().split()
n= int(list1[0])
m= int(list1[1])
a= input().split()
b= input().split()
a= [int(x) for x in a]
b= [int(x) for x in b]

a= sorted(a)
b= sorted(b)

list2=a
i=0
l=n
d=0
mind=1000000
while(i<l):
    j=0
    equal=True
    d= (b[i]-a[0])%m
    for k in range(l):
        if(i+j==l): j=-i
        if((b[i+j]-list2[k])%m!=d): 
            equal=False
            break
        j+=1
    if(equal):
        if(d<mind):
            mind=d
    i+=1
print(mind)
    
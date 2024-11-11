n=int(input())
print(4+(n-1)*3)
print(0,0)
print(1,0)
print(0,1)
print(1,1)
a=1
b=2
for i in range((n-1)):
    print(b,a)
    print(a,b)
    print(b,b)
    a=b
    b+=1

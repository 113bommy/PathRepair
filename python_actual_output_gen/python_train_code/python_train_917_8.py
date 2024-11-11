n=int(input())
a=[int(i) for i in input().split()]
print(a[0],end=" ")
t=a[0]
for i in a[1:]:
    if(i<0):
        print(0,end=" ")
    else:
        t+=i
        print(t,end=" ")
print()
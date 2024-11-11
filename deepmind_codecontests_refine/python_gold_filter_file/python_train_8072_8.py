n = int(input())
c = [int(x) for x in input().split()]

x=0
y=0

a=0
b=n-1

while (a<=b):
    if (x+c[a] <= y+c[b]):
        x+=c[a]
        a+=1
    else:
        y+=c[b]
        b-=1

print(a,n-a) 
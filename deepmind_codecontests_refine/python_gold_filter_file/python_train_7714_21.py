# cook your dish here
l,r=map(int,input().split())
a=r
b=r-1
print("YES")
for i in range(int((r-l+1)/2)):
    print(a,b)
    a-=2
    b-=2
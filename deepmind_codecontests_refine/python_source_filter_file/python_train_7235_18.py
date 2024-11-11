n=int(input())
b=[int(i) for i in input().split()]
x=b[0]
for i in range(len(b)-1):
    x+=abs(b[i]-b[i+1])
print(x)
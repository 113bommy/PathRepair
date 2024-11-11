n = int(input())

print(7+(n-1)*3)
print(0,1000)
print(0,1001)
print(1,1000)
print(2,1000)
print(1,1001)
print(1,999)
print(2,999)
x=2
y=998
for i in range(n -1):
    print(x,y)
    print(x+1, y)
    print(x+1 , y+1)
    x+=1
    y-=1
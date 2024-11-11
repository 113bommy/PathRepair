a, b = map(int,input().split())
y = 0
while(a<b):
    y+=1
    a=a*3
    b=b*2
print(y)
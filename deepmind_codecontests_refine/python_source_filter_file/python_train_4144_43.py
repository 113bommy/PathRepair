a,b=map(int,input().split())
x=0
while a+(a-1)*x<b:
    x+=1
print(x+1)
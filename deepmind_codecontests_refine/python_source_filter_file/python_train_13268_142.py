a=0
for x in range(int(input())):
    x,y=map(int,input().split())
    if(x+2>=y):a+=1
print(a)
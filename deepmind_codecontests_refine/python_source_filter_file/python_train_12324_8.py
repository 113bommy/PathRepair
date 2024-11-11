n=int(input())
y=0
for i in range(n):
    x=input()
    if(x.find('-')):
        y-=1
    else:
        y+=1
print(y)
inp = list(map(int,input().split()))
x= list(map(int,input().split()))
y= list(map(int,input().split()))
for item in x:
    if(item in y):
        print (item,end=" ")
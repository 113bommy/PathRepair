def function(a,b):
    if a!=b:
        if (a+b)%2==1:
            return "-1"
        else:
            return("2")
    elif(a!=0):
        return "1"
    else:
        return"0"
t=int(input())
list=[]
for i in range(t):
    list.append(input().split())
for items in list:
    print(function(int(items[0]),int(items[1])))



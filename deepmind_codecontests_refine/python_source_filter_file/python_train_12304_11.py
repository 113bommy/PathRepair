def ii():return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())
x,y=mi()
if(x==y):
    print(x,end="")
    print("1",end=" ")
    print(y,end="")
    print("2")
elif((y-x)==1):
    print(x,end="")
    print("9",end=" ")
    print(y,end="")
    print("0")
elif(x==1 and y==9):
    print(x,end="")
    print("00",end=" ")
    print(y,end="")
    print("9")
else:
    print("-1")

    
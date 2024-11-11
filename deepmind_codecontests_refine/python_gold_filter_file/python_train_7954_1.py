from sys import stdin
x=str(stdin.readline())
x=[x for x in x]
x.pop()
mid=x.index("^")
ans=0
for i in range(len(x)):
    if x[i]!='^' and x[i]!="=":
        if i<mid:
            ans+=int(x[i])*(mid-i)
        else:
            ans-=int(x[i])*(i-mid)
if ans>0:
    print("left")
elif ans<0:
    print("right")
else:print("balance")    


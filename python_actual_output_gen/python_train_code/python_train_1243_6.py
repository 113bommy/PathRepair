n,x=[int(i) for i in input().split(" ")]
distress=0
for i in range(n):
    query=input()
    if query[0]=="+":
        x+=int(query[2])
    elif query[0]=="-":
        if x-int(query[2])<0:
            distress+=1
        else:
            x-=int(query[2])
print(x,distress)
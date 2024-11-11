from sys import stdin
input=stdin.readline

def intersec(arr):
    a=sorted(arr,key=lambda s:s[0],reverse=True)
    b=sorted(arr,key=lambda s:s[1])

    x, y = 0, 0
    if a[0]==b[0]:
        return max(b[1][1]-a[1][1],0)
    else:
        x=b[0][1]-a[1][0]
        y=b[1][1]-a[0][0]
    return max(x,y,0)
blanck=[]
for i in range(int(input())):
    a,b=map(int,input().strip().split())
    blanck.append([a,b])
print(intersec(blanck))
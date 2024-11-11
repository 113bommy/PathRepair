n=int(input())
d=sorted(list(map(int,input().split())))
d.append(-1)
m=int(input())
t=sorted(list(map(int,input().split())))
x=0
f=0
for i in range(m):
    while d[x]!=t[i]:
        x+=1
        if x==n:
            print("No")
            exit()
    x+=1
print("Yes")

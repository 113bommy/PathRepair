input()
n=[0]*100001
for i in map(int,input().split()):
    n[i]+=i
x=y=0
for j in n:
    a,y=max(x,j+y),x
print(x)
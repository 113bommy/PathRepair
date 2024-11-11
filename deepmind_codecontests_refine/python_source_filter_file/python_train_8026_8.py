# B. Cover Points
n=int(input())
mn=0
for i in range(n):
    x,y=map(int,input().split())
    if x+y>mn:
        mn=x+y
        
print(x+y)
    
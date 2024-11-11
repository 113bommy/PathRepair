cc=0
n=int(input())
for i in range(n):
    x,y,z=map(int,input().split())
    if x+y+z>2:
        cc=cc+1
print(cc)
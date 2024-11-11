n=int(input())
cap=0
temp=0
for i in range(4):
    sub,add=map(int,input().split())
    temp=temp-sub
    temp=temp+add
    if temp>cap:
        cap=temp
print(cap)




















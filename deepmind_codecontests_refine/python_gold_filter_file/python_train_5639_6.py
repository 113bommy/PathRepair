n=int(input())
cap=0
temp=0
for i in range(n):
    sub,add=map(int,input().split())
    temp=temp-sub
    temp=temp+add
    if temp>cap:
        cap=temp
print(cap)




















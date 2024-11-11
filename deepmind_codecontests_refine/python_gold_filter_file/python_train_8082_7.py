n=int(input())
l=list(map(int,input().split()))
od=0
ev=0
for i in l:
    if i%2==0:
        ev+=1
    else:
        od+=1
ans=0
if od>ev:
    ans=(od-ev)//3
print(min(od,ev)+ans)        
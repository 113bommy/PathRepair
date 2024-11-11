n = int(input())
p=list(map(int,input().split()))
z=0
for i in range(n):
    if p[i]!=i+1:
        z+=1
if z>2:print(NO)
else:
    print(YES)

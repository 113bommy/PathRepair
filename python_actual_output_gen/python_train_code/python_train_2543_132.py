L,R,d = map(int,input().split())
i=0
for x in range (L,R+1):
    if x%2==0:
        i+=1
print(i)
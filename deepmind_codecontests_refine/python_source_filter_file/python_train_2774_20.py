n,k = map(int,input().split())
l = list(map(int,input().split()))
l = [0]+l
x = [0]
ans = 0
mi = 10**18+9
for i in range(1,k+1):
    if(l[i]<mi):
        ans = i
        mi = l[i]
print(ans,n//l[ans])

n,k = map(int,input().split())
d = dict()
maxi = 1
for i in range(1,n):
    try:
        if(d[n%i]):
            break
    except:
        d[n%i]=1
        maxi = i
if(k<=maxi):
    print("Yes")
else:
    print("No")
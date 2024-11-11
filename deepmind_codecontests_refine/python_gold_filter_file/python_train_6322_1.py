n,k = map(int,input().split())
l = list(map(int,input().split()))
count = 0
for i in range(n):
    #print(l[i])
    if int(l[i]) <= k:
        #print(l[i])
        count = count + 1
    else :
        break
for i in range(n - 1,count,-1):
    if int(l[i]) <= k:
        count = count + 1
    else :
        break
print(count)
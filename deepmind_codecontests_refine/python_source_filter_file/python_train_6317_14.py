inp = list(map(int,input().split()))
n=inp[0]
k=inp[1]
inp = list(map(int,input().split()))
count=0
for item in inp:
    if(item>k):
        count+=1
if(count==0):
    print (len(inp))
else:
    a=inp
    count=0
    for i in range(len(a)):
        if(a[i]<=k):
            count+=1
        else:
            break
    a.reverse()
    for i in range(len(a)):
        if(a[i]<=k):
            count+=1
        else:
            break
print(count)
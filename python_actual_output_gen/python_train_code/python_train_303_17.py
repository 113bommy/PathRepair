n = int(input())
a = list(map(int,input().split()))
a.insert(0,1000)
m = int(input())

for i in range(m):
    x,y = map(int,input().split())
    if(x>1):
        a[x-1]+=y-1
    if(x<5):
        a[x+1]+=a[x]-y
    a[x] = 0
for i in a[1:]:
    print(i)
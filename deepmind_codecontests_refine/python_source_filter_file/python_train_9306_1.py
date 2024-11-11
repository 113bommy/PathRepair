n,d = map(int,input().split())
l = list(map(int,input().split()))
l.sort()
ct = 0
for i in range(n-1):
    for j in range(i,n-1):
        if(l[j+1] - l[j] <= d):
            ct += 2
print(ct)
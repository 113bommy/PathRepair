n = int(input())
arr = list(map(int , input().split()))[:n]
mini = 0
maxu = 1
maxi = 0
for i in range(0,n):
    if(arr[i]==1):
        mini = i
    elif(arr[i]>maxu):
        maxu = arr[i]
        maxi = i
if(abs(maxi-mini)==n-1):
    print(abs(maxi-mini))
else:
    c = mini
    d = maxi
    e = max(n-mini+1,n-maxi+1)
    print(max(c,d,e))
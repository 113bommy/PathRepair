n = int(input())
arr = list(map(int , input().split()))[:n]
c = min(arr)-1
if(c==0):
    print(-1)
else:
    print(c)
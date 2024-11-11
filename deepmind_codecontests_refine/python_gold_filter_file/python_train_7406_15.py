
R = lambda : map(int,input().split())
  
n = R()
arr = [0]
arr += list(R())
arr += [0]
cnt = 1;
c = []
#print(arr)
for i in range(1,len(arr)):
    if(arr[i] == arr[i-1]):
        cnt += 1
    else:
        if(arr[i-1] == 1):
            c += [cnt]
        cnt = 1

ma = 0
for i in c:
    ma = max(ma,i)

if (arr[1]==1) & (arr[len(arr)-2]==1):
        ma = max(ma,c[0]+c[len(c)-1])

print(ma)
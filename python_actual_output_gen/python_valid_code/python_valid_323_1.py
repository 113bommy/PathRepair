n,t,c = map(int,input().split())
arr = list(map(int,input().split()))+[t+1]
var = 0
count = 0
check = 0
for i in range(n):
    if var==0 and arr[i]<=t:
        start=end=i
        var = 1
        check = 1
    elif var==1 and arr[i+1]>t:
        end=i
        var = 0
        if end-start+1>=c:
            count += end-start+1-c+1
if check==0:
    print(0)
else:
    print(count)
        

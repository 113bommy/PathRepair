n , h = map(int,input().split())
x = list(map(int,input().split()))
count = 0

for i in range(0,n):
    if(x[i]>=h):
        count+=2
    else:
        count+=1
    
print(count)

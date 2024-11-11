
x = input()
n =int(input())
arr = [0]* n*2
for i in range(0,n*2,2):
    arr[i], arr[i+1] = [int(x) for x in input().split()] 
    
sum = [0]*len(x)
sum[1] = 1 if x[0] ==x[1] else 0
for i in range(1,len(x)-1):
    if(x[i]==x[i+1]):
        sum[i+1] =sum[i] +1
    else:
        sum[i+1] = sum[i]
        
for i in range(0,n*2,2):
    print(sum[arr[i+1]-1]-sum[arr[i]-1])
    

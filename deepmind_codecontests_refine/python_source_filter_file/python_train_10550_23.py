import math
def fun(n):
    return (n*(n+1)/2)
n = int(input())
j = int(pow(n*2,0.5))
arr = [fun(i) for i in range(j+1)]
i=1
while(i<j):
    a = arr[j]+arr[i]
    if(a==n):
        print("YES")
        break
    elif(a<n):
        i+=1
    elif(a>n):
        j-=1

else:
    print("NO")
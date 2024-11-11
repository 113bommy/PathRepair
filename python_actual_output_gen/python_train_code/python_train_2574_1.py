def food_processor(arr,k,h):
       time = 0
       n = len(arr)
       if n==0:
              return 0
       res = 0
       curr = 0
       for i in range(n):
             if curr + arr[i] <= h:
                    curr += arr[i]
             else:
                    res += 1
                    curr = arr[i]
             res += curr//k
             curr %= k
             
       res += curr/k
       res += (curr%k !=0)
       return res
              
 
n = list(map(int,input().split()))
k = n[2]
h = n[1]
arr = list(map(int,input().split()))
result = food_processor(arr,k,h)
print(result)
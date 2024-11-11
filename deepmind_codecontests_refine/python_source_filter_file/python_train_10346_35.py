n,k = list(map(int,input().split()))

max_fun=0

for i in range(n):
    fun, time=list(map(int,input().split()))
    
    total_fun=0
    
    if time>k:
        total_fun+=fun-(time-k)
    else:
        total_fun+=fun
    
    if total_fun>max_fun:
        max_fun=total_fun
        
print(max_fun)
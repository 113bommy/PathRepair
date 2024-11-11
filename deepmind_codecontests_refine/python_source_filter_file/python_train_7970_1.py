n , b  = map(int, input().split())
rem = b-240
c= 0
time = 0
for i in range(1, n+1):
    t = 5*i
    time = time + t
    if rem>=time:
        c = c+1
        
        
print(c)
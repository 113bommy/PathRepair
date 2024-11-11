n,m = map(int,input().split())
maximum = n-(m-1)
maximum = (maximum*(maximum-1))//2
t = n//m
a = n%m
if a==0:
    minimum = m*((t*(t-1))//2)
else:
    minimum = (m-a)*((t*(t-1))//2)
    t = t+1
    minimum+=a*(t*(t-1))//2
    
print(minimum,maximum)
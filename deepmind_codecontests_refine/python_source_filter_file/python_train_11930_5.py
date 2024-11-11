n,t,k,d = map(int,input().split())
time1 = (n+k-1)//k*t
# print(time1)

ta,tb = 0,d
while n:
    if ta<=tb:
        ta+=t
    else:
        tb+=t
    n-=1
time2 = max(ta,tb)

# print(time2)
if time1>time2:
    print("YES")
else:
    print("NO")
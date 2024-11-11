def ro(x1,y1,x2,y2):
    return (x1-x2)**2+(y2-y1)**2


r,d = map(int,input().split())
n = int(input())
eps = 10**-5
ans = 0
for i in range(n):
    xi,yi,ri = map(int,input().split())
    d1 = ro(0,0,xi,yi)
    if d1 >= (ri+d)**2 and d1<=(r-ri)**2 and r > ri:
        ans+=1
print(ans)
    
    
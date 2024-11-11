R,d = map(int,input().split())
n = int(input())
c=0
for i in range (n) :
    x,y,r=map(int,input().split())
    p = (x**2 + y**2)**0.5
    if p < R and p > R-d  :
        if p - r >= R-d and p+r <= R:
            c+=1
        
print (c)  
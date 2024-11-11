n , a,b = map(int  , input().split())

q = min(a,b)
p = max(a,b)
ans =  -1
for i in range(1,q//2+1):
    if q//i + p//i >=n:
        ans = max(ans , i)

print(ans)








          
                 

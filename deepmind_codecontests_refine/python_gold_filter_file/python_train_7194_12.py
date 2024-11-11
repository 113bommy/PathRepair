n = int(input())
a = [0]*(n+2)
a = [int(i) for i in input().split()]
a.insert(0,0)
a.insert(n+1,1001)
con = 0
ans = 0
for i in range(1,n+1):
    if a[i] == a[i-1]+1 and a[i] == a[i+1]-1:
        con += 1
        ans = max(ans,con)
    else:
    	con = 0    
print(ans)   
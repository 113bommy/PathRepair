n,m = map(int, input().split())
a = n
b = 1
for i in range(m):
    l,r = map(int,input().split()) 
    a = min(a,r)
    b = max(b,l)
    
print(a-b+1)
n = int(input())
l =list(map(int,input().split()))
l.reverse()
a = [0]*(n+1)
for i,j in enumerate(l):
    if a[j]==0:
        a[j]=i
print(a.index(max(a)))    
    
    
    
    

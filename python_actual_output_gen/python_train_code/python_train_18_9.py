n,m=map(int,input().split())
#print(n,m)
s=set()
for i in range(n):
    s.update(map(int,input().split()))
    #print(s)
if(len(s)==m):
    print("YES")
else:
    print("NO")
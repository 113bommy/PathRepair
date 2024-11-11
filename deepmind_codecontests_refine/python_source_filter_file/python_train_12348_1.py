n=int(input())  
l=list(map(int,input().split()))
l.sort()
flag=False
for i in range(n):
    if l[i+n]<=l[i]:
        print("NO")
        flag=True
        break
if not flag:
    print("YES")
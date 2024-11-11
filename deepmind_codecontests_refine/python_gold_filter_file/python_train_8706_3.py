k = list(map(int,input().split()))
k.sort()
if(k.count(2)>=2 or k.count(1)>=1 or k.count(3)>=3 or k==[2,4,4]):
    print("YES")
else:
    print("NO")

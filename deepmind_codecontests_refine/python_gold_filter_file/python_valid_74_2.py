t = int(input())
for _ in range(t):
    a,b = map(int,input().split())
    am = (a+b+1)//2
    bm = a+b - am
    i = abs(am-a)
    ans = set()
    ans.add(i)
    for j in range(1,min(a,b)+1):
        i += 2
        ans.add(i)
        
    bm = (a+b+1)//2
    am = a+b - bm
    i = abs(am-a)
    ans.add(i)
    for j in range(1,min(a,b)+1):
        i += 2
        ans.add(i)
    print(len(ans))
    for i in sorted(ans):print(i,end=" ")
    print()
    
    
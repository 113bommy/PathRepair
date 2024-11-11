n , m = map(int, input().split())
lst = list(map(int, input().split()))
ans = set()
for i in lst:
    if ans:
        for j in ans.copy():
            ans.add((i + j) % m)
            ans.add(i % m)
            
    else:
        ans.add(i)
    if 0 in ans:
        print('YES')
        break
else:
    print('NO')
    

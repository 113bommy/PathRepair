x = list(map(int, input().split()))
x.sort()
if(1 in x or x.count(2) >= 2 or x == [3, 3, 3] or x == [2, 4, 4]):
    print("YES")
else:
    print("NO")
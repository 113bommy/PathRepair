p = [2,3,5,7,11,13,17,19,23,29,31,37,43,47]
n,m = map(int,input().split())
if n in p and m in p:
    if p.index(n)+1 == p.index(m):
        print("YES")
    else:
        print("NO")
else:
    print("NO")
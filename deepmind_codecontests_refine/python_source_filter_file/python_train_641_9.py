tab = list(map(int, input().split()))
tab.sort()
a,b,c,d = tab
if a+d == b+c or a == b+c+d: print("YES")
else:print("NO")
tab = list(map(int, input().split()))
tab.sort()
a,b,c,d = tab
if a+d == b+c or d == b+c+a: print("YES")
else:print("NO")
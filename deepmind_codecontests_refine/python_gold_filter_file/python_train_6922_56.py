fA,sA = list(map(int,input().split()))
fP ,sP = list(map(int,input().split()))
f = list(map(int,input().split()))
s = list(map(int,input().split()))
new = f+s
newFlags = []
b = s[sA-sP:][0]
a = f[:fP][fP-1]
if b > a:
    print("YES")
else:
    print("NO")

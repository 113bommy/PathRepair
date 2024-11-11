input()
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort()
b.sort()
if a[-1]*b[-1]>max(a[0]*b[0],a[0]*b[-1]) or a[-1]*b[0]>max(a[0]*b[0],a[0]*b[-1]):
    a.pop()
else:
    a.pop(0)
print(max(a[0]*b[0],a[0]*b[-1],a[-1]*b[-1],a[-1]*b[0]))
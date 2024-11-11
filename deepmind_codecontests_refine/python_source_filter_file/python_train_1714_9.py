a = []
a = list(map(int,input().split()))
a.sort()
mid = a[1]
if min(a) == 0:
    r = min(a)
if min(a)+mid>= max(a):
    r = ((((max(a)+min(a))//3)+((((max(a))+min(a))%3)+mid)//3))
else:
    r = mid + min(a)
print(r)
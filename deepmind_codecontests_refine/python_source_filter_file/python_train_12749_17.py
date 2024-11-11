n,l = map(int,input().split())
s = input()
a = [int(num) for num in s.split()]
a.sort()
b = list()
for i in range(0,n-1):
    b.append(a[i+1]-a[i])
b.sort()
ans = max(a[0]-0,l-a[n-1])
if len(b) > 0:
    ans = max(ans,b[len(b)-1])
print('%.10f' % ans)

import bisect
n=input()
a=sorted(map(int,input().split()))
m=a[-1]
q=bisect.bisect_right(a,m/2)
p=q-1
if abs(m/2-a[p])>abs(m/2-a[q]):print(m,a[q])
else:print(m,a[p])
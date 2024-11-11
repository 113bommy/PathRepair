n,m,a = map(int,input().split())
if n%a == 0:
    k = 0
else:
    k = 1
if m%a == 0:
    p = 0
else:
    p = 1
temp = (n/a)+k
temp1 = (m/a)+p
print(temp*temp1)
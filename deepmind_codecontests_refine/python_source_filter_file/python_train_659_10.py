y,k,n = map(int,input().split())
a = (k-(y%k))%k
print(y%k)
print((k-(y%k)))
print((k-(y%k))%k)
if a == 0:
    a += k
flag = False
while(a+y <= n):
    print(a,end = " ")
    flag = True
    a += k
if not flag:
    print(-1)

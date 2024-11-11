
n , k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

b.sort()

for i in range(n):
    if a[i] == 0 :
        a[i] = b.pop()

if sorted(a) == a :
    print('"No"')
else:
    print('Yes')






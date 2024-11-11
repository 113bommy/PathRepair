a =int( input())
d = 0

for x in range(a):
    b ,c = map(int,input().split())
    d += c-b+1
print(d)
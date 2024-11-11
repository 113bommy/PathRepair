a,b,c = map(int,input().split())
for i in range(b):
    c = a*c-b
    print(c)
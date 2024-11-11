n,a,b = map(int , input().split())
num = a + b
for x in map(len , input().split('*')):
    if a < b:
        a,b = b,a
    b -= min(b , x // 2)
    a -= min(a ,x -  x // 2)
print(num - a - b)
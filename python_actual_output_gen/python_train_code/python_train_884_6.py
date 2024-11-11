t = int(input())

for tt in range(t):
    x , y = map(int,input().split())
    a , b = map(int,input().split())

    print(min(min(x , y) * b + (max(x , y) - min(x , y)) * a , (a + b) * a))



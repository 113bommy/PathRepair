a, b = map(int, input().split())
t = 0
f = True


for i in range(1, a+1):
    t += i*5
    if(t > (240 - b) and f):
        print(i-1)
        f = False

if(f):
    print(i)
a, b=map(int, input().split())
m = 0
while b >= a-1 :

    x = str(b)
    for i in range (0, len(x)):
        m=0
        for n in range (0,10):
            z = str(n)
            s = x.count(z)
            if s == 1 :
              m = m+1
        if m == len(x):
            print(b)
            exit()
    b -= 1

print(-1)
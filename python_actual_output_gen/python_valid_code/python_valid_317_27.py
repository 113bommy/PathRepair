t = int(input())
for i in range(t):
    n, m = (map(int, input().split()))
    c = min(n, m)
   # print(c)
    d = max(m, n)
    if c == 1:
        if d == 1:
            print('1')
        else:
            if(d%2==0):
                print(int(d/2))
            else:
                print(int(d/2)+1)

        # print(int(e))
    elif d % 2 == 0:
        print(int(c*d/2))
    else:
        print(int(c*(int(d/2)))+(d-2))

n = int(input())
f = 0
for i in range(10000):
    # x4+y7 = N
    y7 = n-4*i 
    if (y7>=0):
        if (y7%7==0):
            ans = '4'*i + '7'*(y7//7)
            f = 1 
            print(ans)
            break
if (f==0):
    print(-1)
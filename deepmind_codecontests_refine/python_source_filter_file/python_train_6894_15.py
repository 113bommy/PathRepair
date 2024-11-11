t = int(input())
while(t):
    li = [int(i) for i in input().split()]
    m = li[1]
    n = li[0]
    if(m % n == 0):
        print("YES")
    else:
        print("NO")
    t -= 1
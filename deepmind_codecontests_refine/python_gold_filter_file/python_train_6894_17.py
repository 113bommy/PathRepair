t = int(input())
while(t):
    li = [int(i) for i in input().split()]
    n = li[0]
    m = li[1]
    if(n % m == 0):
        print("YES")
    else :
        print("NO")
    t -= 1
t = int(input())
while(t):
    li = [int(i) for i in input().split()]
    a = li[0]
    b = li[1]
    k = li[2]
    if(k % 2 == 0):
        print((a-b)*k//2)
    else:
        print(((a-b)*k//2)+a)
    t -= 1
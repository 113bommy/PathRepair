t = int(input())
for t in range(t):
    a, b = map(int, input().split())
    xor = 0
    rem = (a-1) % 4
    if(rem ==0):
        ans = a-1
    elif rem==1:
        ans = (a-1)^(a-2)
    elif rem == 2:
        ans = (a-1)^(a-2)^(a-3)
    else:
        ans = 0
    if ans == b:
        print(a)
    elif (ans ^ a) == b:
        print(a+2)
    else:
        print(a+1)


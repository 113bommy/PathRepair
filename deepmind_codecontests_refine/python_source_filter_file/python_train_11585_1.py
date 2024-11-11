t = int(input())
# t = 1
for _ in range(t):
    a,b = list(map(int, input().split()))
    tmp = abs(b-a)
    
    if tmp <= 10:
        print(0)
    else:
        if tmp%10 == 0:
            print(tmp//10)
        else:
            print(tmp//10 + 1)
       
    
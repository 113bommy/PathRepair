t = int(input())

for q in range(t):
    n = int(input())
    lis = list(map(int, input().split()))
    
    lis.sort()
    suslis = [i%3 for i in lis]
    maxi= max(lis)
    if maxi%3==0:
        if suslis == [0 for i in lis]:
            print(maxi//3)
        else:
            print(maxi//3 +1)
    elif maxi%3==1:
        if 2 in suslis and (maxi-1 in lis or 1 in suslis):
            print(maxi//3+2)
        else:
            print(maxi//3+1)
    else:
        if 1 in suslis:
            print(maxi//3+2)
        else:
            print(maxi//3+1)

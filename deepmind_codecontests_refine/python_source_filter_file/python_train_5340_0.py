t = int(input())
while t:
    t -= 1;
    n = int(input())
    string = input()
    
    ans = False
    
    for i in range(0, 4):
        if (string[0:i]+string[n-4+i:])=='2020':
            ans = True
            break
    if ans: print("YES")
    else: print("NO")
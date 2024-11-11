for t in range(int(input())):
    a = int(input())
    b = list(map(int,input().strip().split()))
    count = 0
    rcount = 0
    for i in range (a-1):
        if(b[i] + 1 != b[i+1]):
            count += 1
        if(b[i]-1 != b[i+1]):
            rcount += 1
    if(rcount >= 2 and count >= 2):
        print("NO")
    else:
        print("YES")
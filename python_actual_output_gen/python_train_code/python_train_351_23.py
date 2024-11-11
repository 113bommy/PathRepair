n = int(input())
k = [int(i) for i in input().split(' ')]

if k[0] > 15:
    print(15)
else:
    i = 1; c = k[0] + 15
    while i < n-1:
        if c > k[i] and c < 90:
            c = k[i] + 15
        i += 1
    
    if c >= 90:
        print(90)
    else: print(c)
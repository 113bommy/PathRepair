t = int(input())
for _ in range(t):
    n = int(input())
    c,v = 1,n
    for i in range(1,2*n):
        if v == 0:
            break;
        if i%3 == 0 and i%10 == 3 :
            continue;
        else:
            c = i
            v -= 1
    print(c)
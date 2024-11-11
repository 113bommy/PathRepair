
a = 0

k = int(input())

if k > 36:
    print(-1)
    

else:
    while k > 1:
        a = 10*a + 8
        k = k - 2

    if k == 1:
       a = 10*a
    
    print(a)

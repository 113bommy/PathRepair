n = int(input())
m = int(input())
if n == 3:
    print(m%8)
else:
    if m < n*n:
        print(m)
    else:
        print(m%(2**n))
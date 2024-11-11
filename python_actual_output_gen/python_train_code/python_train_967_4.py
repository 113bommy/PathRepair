m = int(input())
p = int(input())

if p == 0:
    print ((m+1)//2 % 3)
elif p == 1:
    print ((0,2,1)[(m-1)%3])
else:
    print ((0,1,2)[(m%6)//2])
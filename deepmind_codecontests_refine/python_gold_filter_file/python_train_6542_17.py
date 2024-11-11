a,b = [int(i) for i in input().split()]

l = [int(i) for i in input().split()]

l2 = [i for i in l if i %2 == 1]

if not l2 :
    print(2**a if b % 2 == 0 else 0)
else:
    print(2**(a-1))
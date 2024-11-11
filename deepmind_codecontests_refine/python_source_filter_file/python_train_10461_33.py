a = [int(x) for x in input().split()]
borrow = (a[0]*a[2]*(a[2]+1)/2)-a[1]
if borrow > 0: print(borrow)
else: print(0)
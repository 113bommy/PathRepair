ar = []
for x in input().split(' '):
    ar.append(int(x))
curr = pow(pow(2, ar[1], 1000000007)-1, ar[0], 1000000007)
print(curr)
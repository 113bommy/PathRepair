n = int(input())
a = [int(x) for x in input().split()]
xor_sum = 0
for x in a:
    xor_sum = xor_sum ^ x

if n % 2 == 0 and xor_sum != 0:
    print("NO")
else:
    print("YES")
    l = [(x,x+1,x+2) for x in range(1,n-1,2)]
    l += list(reversed(l))[1:]
    print(len(l))
    for x in l:
        print(" ".join([str(y) for y in x]))


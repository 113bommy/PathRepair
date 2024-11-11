n = int(input()) 
#n, m = map(int, input().split()) 
#s = input()
c = list(map(int, input().split()))
k = c[0]
l = 10 ** 9
while k % 3 == 0 or k % 2 == 0:
    if k % 3 == 0:
        k //= 3
    else:
        k //= 2
    l = k
for i in range(n):
    k = c[i]
    while k % 3 == 0 or k % 2 == 0:
        if k % 3 == 0:
            k //= 3
        else:
            k //= 2
    if l != k:
        print('No')
        break
else:
    print('Yes')
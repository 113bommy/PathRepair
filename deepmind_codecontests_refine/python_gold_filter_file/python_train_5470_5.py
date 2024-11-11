def nod(a,b):
    while a != 0 and b != 0:
        if a > b:
            a = a % b
        else:
            b = b % a
    return (a + b)
n = int(input())
m = list(map(int, input().split()))
k = [m[len(m)-1]]*(2*(len(m)))
k[0] = m[0]
l = 0
for i in range(n-1):
    k[i+l] = m[i]
    if nod(m[i],m[i+1]) != 1 :
        l += 1
        k.insert(i+l,1)
k = k[:len(m) + l]
print(l)
print(' '.join(map(str, k)))

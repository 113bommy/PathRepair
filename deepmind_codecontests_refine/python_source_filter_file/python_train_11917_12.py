n = int(input())
def sumof(n):
    return (n * ( n + 1)) // 2
print(sumof(4))
i = 1
s = 0
count = 0

while s <= n:
    print('s =',s, 'i  =', i)
    s += sumof(i)
    count += 1
    if s + sumof(i + 1) <= n:
        i += 1
    else:
        break
print(count)

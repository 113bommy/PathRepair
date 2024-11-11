n =int(input())
n = n%10
x = int(input())
a, b, c = 0, 1, 2
for i in range(1, n+1):
    if i % 2 == 1:
        a, b = b, a
    else:
        b, c = c, b
        
d = [a, b, c]
print(d[x])
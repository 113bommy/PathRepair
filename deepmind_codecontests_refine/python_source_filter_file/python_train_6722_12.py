n = int(input())
a = int(n**.5)
 
while n % a:
    a -= 1
 
print(a, n/a)

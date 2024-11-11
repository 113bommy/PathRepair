n = int(input())
x = 1
xx = 1
for i in range(1,n+1):
    x = x*i
for i in range(1,n//2+1):
    xx = xx*i
a = x//xx//xx
a = a*xx*xx//(n//2)
a = a//2
print(a)

        

n = input()
x = 0
for i in range(1,len(n)):

    
    x = x+ 10**i - 10**(i-1)
    
r = x + (int(n) - 10**(len(n)-1) + 1)*len(n)

print (r)
 
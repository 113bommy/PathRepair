def prime_test(x):
    j = x;
    for i in range(2, x):
        if (j % i == 0):
            return False
    return True        	

n = int(input())
ans = 0
for i in range(2, n + 1):
    if (prime_test(i) == True):
        j = i;
        while (j <= n):
            ans += 1
            j *= i
print (ans)
for i in range(2, n + 1):
    if (prime_test(i) == True):
        j = i;
        while (j <= n):
            print(j) 
            j *= i


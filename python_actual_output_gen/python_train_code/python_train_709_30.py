s = ['byte', 'short', 'int', 'long', 'BigInteger ']
q = [2**8, 2**16, 2**32, 2**64]
n = int(input())
res = s[4]
for i in range(4):
    if (n < q[i]): 
        res = s[i]; break
print(res)

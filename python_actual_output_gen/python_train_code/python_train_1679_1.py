k = 1
cur = 1
i = int(input())
ret = 1;
while cur<i:
    k+=1
    if i%cur==0:
        ret = cur;
    cur = (2**k-1)*(2**(k-1))
print (ret);
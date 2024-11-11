n = int(input())
i = 1;
while 1:
    t = (2**i - 1) *(2**(i-1))
    if t < n:
       if n%t==0:
           rs = t
    else:
        break
    i+=1
print(rs)
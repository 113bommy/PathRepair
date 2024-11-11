n = int(input())
m = int(input())
t = m
log = 0
while(t>1):
    log += 1
    t //= 2
if(n>log):
    print(m)
else:
    print(m % 2**n)

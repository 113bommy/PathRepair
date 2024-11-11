n,l,r=map(int,input().split())
a=0
b=0
sum1 = n-l+1
for i in range(l):
    a = a + 2**i
p = min(r,n)
max_sum = (2**(p)-1)+(2**(r-1)*(max(0,n-r)))
print(sum1 + a-1, max_sum)

    

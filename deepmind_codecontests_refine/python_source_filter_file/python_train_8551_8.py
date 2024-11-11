import math
#print(30%21)
#print(40%31)
a, b=map(int, input().rstrip().split())
divisors=[]
abs1=abs(a-b)
for i in range(1, int(math.sqrt(abs1))+1):
    if abs1%i==0:
        divisors.append(i)
        divisors.append(int(abs1/i))
min1=10**9
c=0
for j in range(len(divisors)):
    q=divisors[j]
    if a%q!=b%q:
        continue
    if a%q==0:
        k=0
        lcm1=int(((a+k)*(b+k))/math.gcd((a+k), (b+k)))
        if lcm1<min1:
            min1=lcm1
            c=k
    if a%q!=0:
        k=(q-a)%q
        lcm1 = int(((a + k) * (b + k)) / math.gcd((a + k), (b + k)))
        if lcm1 < min1:
            min1 = lcm1
            c = k
print(c)



import sys
num=sys.stdin.readline()
num=int(num)
first=0
ans =0
second = 10**8
for i in range (1,num+1):
    first=float(num)/i
    if first == int(first):
        if abs(first-i) < second :
            second = abs(first - i)
            ans=i

print (int (min(num/ans , ans)) ,int ( max(num/ans ,ans )))

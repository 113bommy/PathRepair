n = int(input())
if n%2 ==0:
    term = n//2
    sum1 = (term*(2+n))//2
    sum2 = (term*(1+n-1))//2
else:
    odd_term = (n+1)//2
    sum1 = ((odd_term-1)*(2+n-1))//2
    sum2 = (odd_term*(1+n))//2
print(sum1,sum2)
print(sum1 - sum2)
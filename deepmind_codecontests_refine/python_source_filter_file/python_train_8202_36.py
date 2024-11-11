from functools import reduce
n = int(input())
print(reduce(lambda x,y:x+y, { n//i - 1 for i in range(1, int(n**0.5)+1) if n%i==0 and n//i-i>=2 }))

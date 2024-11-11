a,b,c,k=[int(i) for i in input().split()]
print(k if k<= a else a if k <=a+b else 2a+b-k)
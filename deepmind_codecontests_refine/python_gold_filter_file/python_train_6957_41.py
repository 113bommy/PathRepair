a,b=input().split()
c=int(a+b)
print('Yes' if (int(c**(1/2)))**2==c else 'No')

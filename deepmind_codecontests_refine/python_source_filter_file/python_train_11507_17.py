n=int(input())
a=n / 1 * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 
b=a * (n - 5) / 6
c=b * (n - 6) / 7
print(int(a+b+c))

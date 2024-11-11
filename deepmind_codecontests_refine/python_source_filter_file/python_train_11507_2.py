n = int(input())
a = int(n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)*(n-6))/5040
b = int(n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5))/720
c = int(n*(n-1)*(n-2)*(n-3)*(n-4))/120
print(int(a+b+c))
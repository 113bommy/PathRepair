b=int(input())
a=int(input())
n=int(input())
if a<n and b<n:
    print(n-(a+b)+1)
else:
    print(min(a, b, n) + 1)
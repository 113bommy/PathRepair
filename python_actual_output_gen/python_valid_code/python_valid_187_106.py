n,a,b = map(int, input().split())

t = n //(a+b)
s = min(n-(a+b), a)
print(t*a+s)
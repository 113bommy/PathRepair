n,a,b = map(int, input().split())
ab=a+b
print(n//ab*a + n-n//ab*(ab))
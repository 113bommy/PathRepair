n=int(input())
print(sum(n//i-1 for i in range(1,int((n+1)**0.5)) if n%i<1))

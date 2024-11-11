n = int(input())
print(sum(i for i in range(1, n//2) if n%i==0))
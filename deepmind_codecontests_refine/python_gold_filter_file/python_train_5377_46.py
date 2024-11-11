n=int(input())
print(len([i for i in range(1,n//2+1) if n%i==0]))
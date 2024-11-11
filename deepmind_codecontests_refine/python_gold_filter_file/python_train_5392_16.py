n=int(input())
s=input()
m=n//2
t=s[:m]
print('Yes' if s==t+t else 'No')
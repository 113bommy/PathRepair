d,n=map(int,input().split())
print(n*100**d if n!=100 else 100**(d+1)+100**d)
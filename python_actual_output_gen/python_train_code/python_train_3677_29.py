n=input()
print('Yes' if int(n)%sum(map(int,n)) else 'No')
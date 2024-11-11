N=input()
s=sum([int(i) for i in N])

print('Yes' if N%s==0 else 'No')
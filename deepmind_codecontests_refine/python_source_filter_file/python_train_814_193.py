a,b,c=input().split()
print('Yes' if a[-1:]==b[:1] and b[-1:]==c[0:1] else 'No')

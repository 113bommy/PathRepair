a, b, c = map(int, input().split())
print('Yes' if (c-2*a-2*b)>0 and 4*a*b < (c - a- b)**2 else 'No')
s=list(str(input()))
len(s)
print('Yes' if len(list(set(s)))==len(s) else 'No')
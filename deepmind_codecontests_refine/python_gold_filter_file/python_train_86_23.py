s = list(map(int,input().split()))
print('Yes' if max(s)*2==sum(s) else 'No')
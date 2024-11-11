copy,original=map(int,input().split())
if copy==1 and original==0:
    print('No')
    exit()
if copy==2 and original==1:
    print('No')
    exit()
if copy>0 and original<=1:
    print('No')
    exit()
if original>copy+1:
    print('No')
    exit()
if copy%2==0 and original%2==0:
    print('No')
    exit()
if copy%2 and original%2:
    print('No')
    exit()
print('Yes')
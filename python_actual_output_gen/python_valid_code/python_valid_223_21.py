n=int(input())
for i in range(1,n//7+1):
    if (n-7*i)%4==0:print('Yes');exit()
print('No')
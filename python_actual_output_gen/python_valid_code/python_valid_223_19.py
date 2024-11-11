n = int(input())
for i in range(n//7+1):
    if (n-7*i)%4==0:
        print('Yes')
        break
    else:
        print('No')
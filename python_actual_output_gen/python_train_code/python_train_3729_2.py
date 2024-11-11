num = int(input())
if(num%2==0):
    print(2**((num//2)+1))
else:
    n = num//2+2
    print(n*(n-1)*2)
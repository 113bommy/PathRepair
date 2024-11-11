n=int(input())
if n%2==1:print(0)
else:
    sum=0
    for i in range(1,18):
        sum+=n//(10**i)
    print(sum)
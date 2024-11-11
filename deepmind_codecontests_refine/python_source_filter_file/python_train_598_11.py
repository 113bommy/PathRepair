n=int(input())
I=list(map(int,input().split()))
num=1000
for i in range(n-1):
    if I[i]<I[i+1]:
        p=num//I[i])
        num-=p*I[i]
        num+=p*I[i+1]

print(num)

n=int(input())
cnt=1
while(n!=1):
    cnt+=10-n%10
    n+=(10-n%10)
    while(n%10==0):
        n=n//10
print(cnt)

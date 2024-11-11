a=int(input())
cnt=int(0)
while a>0:
    if a%2==1:
        cnt+=1
    a/=2
print(int(cnt))
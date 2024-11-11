N=int(input())
cnt=0
for x in range(1,N+1):
    if len(str(x))%2==1:
        cnt+=1
print(cnt)
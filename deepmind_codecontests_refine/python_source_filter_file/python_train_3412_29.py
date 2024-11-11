k = int(input())
if k%2==0 or k%5==0:
    print(-1)
    exit()
s=7
cnt=1
while s!=0:
    s=(s*10+7)%k
    cnt+=1
    #print(s)
print(cnt)
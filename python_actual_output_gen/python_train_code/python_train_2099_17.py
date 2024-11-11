st = input()
queries=int(input())
cnt = 1
lis = []
lis.append(cnt)
for i in range(1,len(st)):
    if st[i] == st[i-1]:
        cnt += 1
    lis.append(cnt)
print(lis)
while(queries>0):
    l,r = map(int,input().split())
    l -= 1
    r -= 1
    print(lis[r]-lis[l])
    queries -= 1

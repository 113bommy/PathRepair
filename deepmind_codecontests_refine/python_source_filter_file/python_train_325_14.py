n,y,x = map(int,input().split())
s = input()
cnt = 0
for i in range(1,y):
    if i==x+1:
        if s[-i]=='0':
            cnt+=1
    else:
        if s[-i]=='1':
            cnt+=1
print(cnt)
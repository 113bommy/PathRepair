N = int(input())
a = list(map(int,input().split()))
cc = []
res = s[0]
for i in range(1,N):
    res^ = s[i]
if res == 0:
    print('Yes')
else:
    print('No')
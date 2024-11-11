n = int(input())
l = []
for i in range(n):
    a,b = map(int,input().split())
    l.append((a,1))
    l.append((b+1,0))
l.sort()
ans = [0 for i in range(n+1)]
val = 0;
for i in range(2*n-1):
    if(l[i][1]==1):
        val += 1
    else:
        val -= 1
    ans[val] += l[i+1][0] - l[i][0]
for i in ans[1:]:
    print(i,'',sep='',end='')


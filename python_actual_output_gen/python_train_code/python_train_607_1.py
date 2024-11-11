n,m = map(int,input().split())
mini = min(m,n)
mini += 1
print(mini)
for i in range(mini):
    print(i,i)
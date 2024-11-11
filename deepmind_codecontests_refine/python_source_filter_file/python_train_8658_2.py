n,l,r = map(int,input().split())
tmp = l-1
ans1 = 1*(n-tmp)
a = 2
for i in range(tmp):
    ans1+=2
    a*=2
tmp = r-1
ans2 = 0
a = 1
for i in range(tmp):
    ans2+=a
    a*=2
ans2 += (a)*(n-tmp)
print(ans1,ans2)
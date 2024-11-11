n,m=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
m2=0
for i in range(len(l1)):
    m1=1000000
    for j in range(len(l2)):
        m1=min(m1,l1[i]&l2[j])
    m2=max(m1,m2)


for i in range(len(l1)):
    ans=100000000
    for j in range(len(l2)):
        ans = min(ans,m2 | (l1[i]&l2[j]))
        # print("here ans and m2 = ",ans,m2)
    m2 = max(m2,ans)
    # print("updated m2 = ",m2)
print(m2)
        
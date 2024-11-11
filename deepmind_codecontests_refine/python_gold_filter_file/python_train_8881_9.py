t=int(input())

for tests in range(t):
    n=int(input())
    a=[int(i) for i in input().split(' ')]
    b=[int(i) for i in input().split(' ')]



    if sum(a)!=sum(b):
        print(-1)
        continue


    ans=[]
    l=0
    g=0
    while True:
        while l<len(a) and a[l]>=b[l]:
            l+=1
        while g<len(a) and a[g]<=b[g]:
            g+=1
        if g==len(a) or l==len(a):
            break
        a[l]+=1
        a[g]-=1
        ans.append([g+1,l+1])








    print(len(ans))
    for i in range(len(ans)):
        print(ans[i][0],ans[i][1])






'''
1
4
1 2 3 4
3 1 2 4
'''
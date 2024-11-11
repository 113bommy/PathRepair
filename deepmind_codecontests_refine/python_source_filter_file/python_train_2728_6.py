'''input
3
5
1 2 3 4 5
4
2 0 1 9
2
2019 2020
'''
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    flag=0
    for i in range(n-1):
        if a[i]+1<a[i+1] or a[i+1]+1<a[i]:
            print("YES")
            print(a[i],a[i+1])
            flag=1
            break
    if flag==0:
        print("NO")
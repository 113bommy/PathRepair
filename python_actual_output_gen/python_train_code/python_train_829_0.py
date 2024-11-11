"""
5 1 20
0 27 32 21 19


7 3 50
62 0 0 0 99 33 22

10 5 100
1 0 1 0 0 0 0 0 1 1
 """

n, m, k=map(int, input().split())
arr=[int(x) for x in input().split()]
ans=100000
m-=1
for i in range(0,n):
    if(arr[i]==0 or arr[i]>k):
        continue
    else:
        ans=min(ans,abs(m-i))

print(ans)

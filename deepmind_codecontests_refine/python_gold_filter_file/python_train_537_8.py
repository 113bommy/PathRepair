#sys.stdout=open("output.txt", 'w')
#sys.stdout.write("Yes" + '\n')
#from  sys import stdin
#input=stdin.readline
#a = sorted([(n, i) for i, n in enumerate(map(int, input().split()))])
# from collections import Counter
# import sys
#s="abcdefghijklmnopqrstuvwxyz"
#n=int(input())
#n,k=map(int,input().split())
#arr=list(map(int,input().split()))
#arr=list(map(int,input().split
'''n=int(input())
abc=[]
for i in range(n):
    abc.append(list(map(int,input().split())))
dp=[[-1,-1,-1] for i in range(n)]


for i in range(n):
    if i==0:
        for j in range(3):
            dp[i][j]=abc[i][j]
    else:
        dp[i][0]=max(dp[i-1][1]+abc[i][0],dp[i-1][2]+abc[i][0])
        dp[i][1]=max(dp[i-1][2]+abc[i][1],dp[i-1][0]+abc[i][1])
        dp[i][2]=max(dp[i-1][0]+abc[i][2],dp[i-1][1]+abc[i][2])
print(max(dp[n-1]))'''

from collections import Counter
for _ in range(int(input())):
    n,k,d= map(int, input().split())
    arr=list(map(int,input().split()))
    ans=len(set(arr[:d]))
    #print(ans)
    if n==d:
        print(ans)
    else:
        q = Counter(arr[:d])
        # print(q)
        cnt = 0
        m =ans
        for i in range(d, n):
            if arr[i] not in q:
                q[arr[i]] = 1
                ans += 1
            elif q[arr[i]] > 0:
                q[arr[i]] += 1
            elif q[arr[i]] == 0:
                q[arr[i]] = 1
                ans += 1
            q[arr[cnt]] -= 1
            if q[arr[cnt]] == 0:
                ans -= 1
                # print("ans",ans)
            cnt += 1
            m = min(m, ans)
        print(m)




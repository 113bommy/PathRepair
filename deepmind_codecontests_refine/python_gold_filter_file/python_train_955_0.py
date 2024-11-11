import sys
input = sys.stdin.readline
q = int(input())
for i in range(q):
    n,r = map(int, input().split())
    lis = list(set((map(int, input().split()))))
    lis.sort(reverse=True)
    lis.append(-1)
    cnt = 0
    ra = 0
    for i in range(n+10):
        if lis[i]-ra<=0:
            print(cnt)
            break
        ra+=r
        cnt+=1
    
    

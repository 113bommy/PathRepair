import sys

int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    for _ in range(II()):
        n=II()
        aa=LI()
        s=set(aa)
        enc={a:i for i,a in enumerate(sorted(s))}
        aa=[enc[a] for a in aa]
        #print(aa)

        first = [False] * n
        fin = [False] * len(s)
        for i in range(n):
            if fin[aa[i]]: continue
            first[i] = True
            fin[aa[i]] = True
        #print(first)

        end = [False] * n
        fin = [False] * len(s)
        for i in range(n - 1, -1, -1):
            if fin[aa[i]]: continue
            end[i] = True
            fin[aa[i]] = True
        #print(end)

        last=[-1]*len(s)
        dp=[[0]*3 for _ in range(n)]
        mx=0
        for i,a in enumerate(aa):
            val=1
            i0=last[a]
            if i0!=-1:val=dp[i0][0]+1
            dp[i][0]=val
            mx=max(mx,val)

            val = 1
            if i0 != -1: val = dp[i0][1] + 1
            i1 = -1
            if a: i1 = last[a - 1]
            if i1 != -1:
                val = max(val, dp[i1][0] + 1)
                if end[i1] and first[i]: val = max(val, dp[i1][1] + 1)
            dp[i][1] = val
            mx=max(mx,val)

            val = 1
            if i0 != -1: val = dp[i0][2] + 1
            if i1 != -1:
                val = max(val, dp[i1][0] + 1)
                if end[i1]: val = max(val, dp[i1][1] + 1)
            dp[i][2] = val
            mx=max(mx,val)

            last[a]=i

        #print(dp)
        print(n-mx)

main()
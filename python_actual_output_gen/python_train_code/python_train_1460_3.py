def cali(subset):
    z = [1-i for i in subset]
    ans = 0
    for i in range(len(subset)):
        ha = subset[i]
        for j in range(len(subset)):
            if i!=j:

                ha*=z[j]

        ans+=ha
    return ans
def solve():

    n = int(input())
    l = list(map(float,input().split()))

    l.sort()
    if l[-1]>=0.5:
        print(l[-1])
    else:
        ans = 0
        yo = -1
        ha = []
        for i in range(4):
            ha.append(l[yo])
            z = cali(ha)
            ans = max(ans,z)
            yo-=1
            if yo == -(n+1):
                break

        print(ans)











# t = int(input())
# for _ in range(t):

solve()




import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
n, *abc = map(int, input().split())
s = [input().rstrip()for _ in range(n)]
cond = {'AB': (0, 1), 'AC': (0, 2), 'BC': (1, 2)}
legend = ('A', 'B', 'C')
ans = []


def dfs(i):
    if -1 in abc:
        return 0
    elif i == n:
        print('Yes')
        print(*ans, sep='\n')
        exit()
        # return 0
    else:
        idx1, idx2 = cond[s[i]]
        abc[idx1] += 1
        abc[idx2] -= 1
        ans.append(legend[idx1])
        dfs(i+1)
        ans.pop()
        abc[idx1] -= 1
        abc[idx2] += 1

        abc[idx1] -= 1
        abc[idx2] += 1
        ans.append(legend[idx2])
        dfs(i+1)
        ans.pop()
        abc[idx1] += 1
        abc[idx2] -= 1


dfs(0)
print('No')

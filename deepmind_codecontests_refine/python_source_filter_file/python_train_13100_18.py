import collections
N = int(input())
A = list(map(int,input().split()))
c = collections.Counter(A)
ans = [i[0] for i in c.items() if i[1] >= 2]
ans = [i[0] for i in c.items() if i[1] >= 4]
ans.extend([0,0])
ans.sort(reverse=True)
print(ans[0]*ans[1])
n = int(input())
least = [1]*(n+1)
op = [0] + list(map(int, input().split()))
pa = [0,0] + list(map(int, input().split()))
for i in range(2, n+1):
    least[pa[i]] = 0
leaves = sum(least)-1
for i in range(n,1,-1):
    if op[pa[i]] == 0:
        least[pa[i]] += least[i]
    else:
        if least[pa[i]] == 0:
            least[pa[i]] = least[i]
        else:
            least[pa[i]] = min(least[pa[i]],least[i])
print(n-least[1]+1)
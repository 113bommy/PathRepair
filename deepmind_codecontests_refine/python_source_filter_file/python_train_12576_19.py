N = int(input())
s = [input() for i in range(N)]
l1 = [s[i].count('AB') for i in range(N)]
l2 = [1 if s[i][0] == 'B' else 0 for i in range(N)]
l3 = [1 if s[i][-1] == 'A' else 0 for i in range(N)]
l4 = [l2[i]*l3[i] for i in range(N)]
if min(sum(l2),sum(l3)) == sum(l4):
    a = max(min(sum(l2),sum(l3))-1,0)
else:
    a = min(sum(l2),sum(l3))
print(sum(l1) + a)
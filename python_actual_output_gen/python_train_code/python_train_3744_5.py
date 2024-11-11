n = int(input())
data = input()
ans = 0
count = {'U': 0, 'D': 0, 'L': 0, 'R': 0}
for c in data:
    count[c] += 1
ans += (max([count['U'], count['D']]) * 2 + max([count['L'], count['R']]) * 2)
print(str(ans))

def solve(l,s):
    ans = 0
    for i in range(len(s)-2):
        ans += abs(l.index(s[i])-l.index(s[i+1]))
    return ans
for _ in range(int(input())):
    l = list(input())
    s = input()
    print(solve(l,s))
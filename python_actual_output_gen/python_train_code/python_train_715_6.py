s = input()[::-1]
size = len(s)
s += "9"

ans = 0
bef = 0

for i in range(size):
    v1 = int(s[i])
    v2 = int(s[i+1])
    if v1+bef>=6 or (v1+bef>=5 and v2>=5):
        ans += 10-(v1+bef)
        bef = 1
    else:
        ans += (v1+bef)
        bef = 0

ans += bef
print(ans)
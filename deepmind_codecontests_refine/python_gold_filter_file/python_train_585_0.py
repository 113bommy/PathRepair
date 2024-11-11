k, d, t = map(int, input().split())
cnt = (k + d - 1) // d;
per = cnt * d
bat = k * 2 + (per - k);
cntbat = (2 * t) // bat;
ost = (2 * t) % bat
ans = 0.0 + per * cntbat
if k * 2 >= ost:
    ans += ost / 2
else:
    ost -= 2 * k
    ans += k + ost
print(ans)

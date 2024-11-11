ans = [int(input()) for _ range(6)]
print(':(' if abs(ans[0]-ans[4]) <= ans[-1] else 'Yay!')
ans = [int(input()) for _ in range(6)]
print(':(' if abs(ans[0]-ans[4]) <= ans[-1] else 'Yay!')
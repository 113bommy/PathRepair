I, O, T, J, L, S, Z = map(int,input().split())
ans = (I // 2) * 2 + (J // 2) * 2 + (L // 2) * 2 + O
if I > 0 and J > 0 and L > 0:
    ans = max(ans, ((I - 1) // 2) * 2 + ((J - 1) // 2) * 2 + ((L - 1) // 2) * 2 + O)
print(ans)
S = input()
if 'C' in S[:-1]:
    a = S.index('C')
    if 'F' in S[a:]:
        print("Yes")
        exit()
print("No")
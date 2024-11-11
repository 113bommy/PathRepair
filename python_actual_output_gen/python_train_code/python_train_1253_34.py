S = input()
ans = 'WA'
if S[0] == 'A' and S[2:-1].count('C'):
    if S[1:].replace('C', '').islower():
        ans = 'AC'
print(ans)
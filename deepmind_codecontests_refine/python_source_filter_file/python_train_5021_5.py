n = int(input())
braces = input()
open_nr = braces.count('(')
closed_nr = braces.count(')')
ans = 0
if open_nr != closed_nr:
    print(-1)
else:
    balance = 0
    balances = []
    for brace in braces:
        if brace == '(':
            balance += 1
        elif brace == ')':
            balance -= 1
        else:
            raise
        balances.append('+' if balance >= 0 else '-')
    ans = sum(len(seg) + 1 for seg in ''.join(balances).split('+') if seg)
print(ans)
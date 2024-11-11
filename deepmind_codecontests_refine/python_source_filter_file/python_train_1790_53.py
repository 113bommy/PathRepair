x = int(input())
ans = []
for i in range(x):
    q = int(input())
    if q == 2:
        ans.append('2')
    elif q % 2:
        ans.append('0')
    else:
        ans.append('1')
print('\n'.join(ans))
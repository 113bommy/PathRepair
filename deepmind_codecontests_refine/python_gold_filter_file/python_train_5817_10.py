s = input()
ans = s
while 'B' in ans:
    ans = ans.lstrip('B').replace('0B', '').replace('1B', '')
print(ans)
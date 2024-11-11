s = input()
ans = s
while 'b' in ans:
    ans = ans.lstrip('b').replace('0b', '').replace('1b', '')
print(ans)
k = int(input())
ans = 'YES'
panels = ''
for i in range(4):
    panels += str(input())
for i in range(1, 9, 1):
    if panels.count(str(i)) > 2*k:
        ans = 'NO'
        break
print(ans)
exit(0)
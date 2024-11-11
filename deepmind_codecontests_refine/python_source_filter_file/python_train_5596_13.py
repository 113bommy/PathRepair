x = str(input())
a = x.split('.')
if a[0][len(a[0])-1] == '9':
    ans = "GOTO Vasilisa"
else:
    if int(a[1][0]) < 5:
        ans = a[0]
    else:
        ans = int(a[0]) + 1
print(ans)
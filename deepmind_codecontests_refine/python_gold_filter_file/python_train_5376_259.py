n = int(input())
m = int(input())
if n >= 27:
    print(m)
else:
    ans = m % (2 ** n)
    print(ans)

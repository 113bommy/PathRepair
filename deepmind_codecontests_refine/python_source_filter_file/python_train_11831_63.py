a = input()

ans = 0

for i in a:
    if i in [ 'a', 'e', 'i', 'o', 'u', '0', '2', '4', '6', '8' ]:
        ans += 1

print( ans )

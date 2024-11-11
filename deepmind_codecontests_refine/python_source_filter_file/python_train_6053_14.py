
t1 = '(('
t2 = '()'
t3 = ')('
t4 = '))'

cnt1 = int(input())
cnt2 = int(input())
cnt3 = int(input())
cnt4 = int(input())

ans = 1

if cnt1 != cnt4 or (cnt2 > 0 and cnt1 == 0):
    ans = 0

print(ans)


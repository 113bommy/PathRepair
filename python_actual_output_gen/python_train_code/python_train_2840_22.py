def f(a):
    if len(str(a)) == 0:
        return '0' + str(a)
    return a
hh, mm = map(int, input().split(':'))
aa = hh * 60 + mm
aa += int(input())
aa %= 24 * 60
mm = aa % 60
aa //= 60
print(f(aa), ':', f(mm), sep = '')

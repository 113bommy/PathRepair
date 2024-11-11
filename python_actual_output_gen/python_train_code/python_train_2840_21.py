h, m = map(int, input().split(':'))
a = int(input())

a %= 720
hh = h + a // 60
mm = m + a % 60
hh = hh + mm // 60
hh %= 24
mm = mm % 60
print(('0' + str(hh) if hh < 10 else str(hh)) + ':' + ('0' + str(mm) if mm < 10 else str(mm)))
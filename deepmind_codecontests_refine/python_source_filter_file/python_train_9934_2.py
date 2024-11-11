h,m = map(int,input().split(':'))
sh,sm = map(int, input().split(':'))
hh = h - sh
mm = m - sm
if mm < 0:
    h -=1
    mm = 60 - abs(mm)
if hh < 0:
    hh = 24 - abs(hh)
if len(str(hh)) == 1:
    hh = '0' + str(hh)
if len(str(mm)) == 1:
    mm = '0' + str(mm)
print(str(hh) + ':' + str(mm))
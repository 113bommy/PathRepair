h,m=map(int,input().split(':'))
i=0
while h//24!=m%24 or h%24!=m//24:
    i,m = i+1, m+1
    if m>=60:
        m=0
        h+=1
    h%=24
print(i)
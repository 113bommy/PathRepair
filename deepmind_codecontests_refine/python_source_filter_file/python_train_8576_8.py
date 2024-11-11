n=input()
last=int(n[-1])
blast=int(n[-2])
first=n[0]
second=int(n[1])
if first!='-':
    print(n)
elif first=='-' and last==0 and second==blast:
    print('0')
elif first=='-' and last==0 and second!=blast:
    n=n[0:-2]
    last=str(last)
    print(n+last)
elif last>blast:
    n=n[0:-1]
    print(n)
elif blast>last:
    n=n[0:-2]
    last=str(last)
    print(n+last)
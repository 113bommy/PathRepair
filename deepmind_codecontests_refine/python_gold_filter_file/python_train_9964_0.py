numset=set()
def num(now,n):
    if(n==1):
        numset.add(now+1)
        numset.add(now+5)
        numset.add(now+10)
        numset.add(now+50)
    else:
        num(now+1,n-1)
        num(now+5,n-1)
        num(now+10,n-1)
        num(now+50,n-1)
n=int(input())
if(n<11):
    num(0,n)
    print(len(numset))
else:
    print(292 + 49*(n-11))
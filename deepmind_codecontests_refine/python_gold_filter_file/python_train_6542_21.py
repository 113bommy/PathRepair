def check(a):
    for i in a:
        if i%2:
            return True
    return False

n,p = map(int, input().split())
a = list(map(int,input().split()))
if check(a):
    print(2**(n-1))
elif p==0:
    print(2**n)
else:
    print(0)
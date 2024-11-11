# cook your dish here
def f(n,m,k):
    if m==1:
        if k==0: return True
        else: return False
    total = (n*m)/2
    maxh = n*(m//2)
    maxv = (n//2)*m 
    minh = total - maxv
    
    if k==minh or k==maxh:return True
    if k<minh or k>maxh:
        return False
    if m==2:
        if n%2==1 and k%2==0: return False
        if n%2==0 and k%2==1: return False
    elif m!=2 and k%2==1: return False
    return True

tc = int(input())
for i in range(tc):
    n,m,k = list(map(int,input().strip().split()))
    if f(n,m,k):
        print('YES')
    else:
        print('NO')
        
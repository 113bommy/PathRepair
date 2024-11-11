n,m,r = map(int,input().split(' '))
s1 =list( map(int,input().split(' ')))
s2 =list( map(int,input().split(' ')))
if(max(s2)>=max(s1)):
    min_s = min(s1)
    q = r//min_s
    r = r-min_s*q
    r += max(s2)*q
    print(r)
else:
    print(r)
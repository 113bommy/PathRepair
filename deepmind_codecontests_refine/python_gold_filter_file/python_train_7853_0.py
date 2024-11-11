input()
l=list(map(int,input().split()))
a=l.count(max(l));b=l.count(min(l))
print((max(l)-min(l)),a*b if max(l)!=min(l) else int(a*(a-1)/2))
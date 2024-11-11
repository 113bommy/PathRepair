n=int(input())
a=[int(i) for i in input().split()]
if len(a)==1:
    print('0')
else:
    print(len(a)-a.count(min(a))-a.count(max(a))) if min(a)!=max(a) else print(a[0])


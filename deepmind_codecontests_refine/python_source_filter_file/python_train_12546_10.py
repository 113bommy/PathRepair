n = int(input())
l = list(map(int,input().split()))
o = [i for i in l if i&1]
e = [i for i in l if not i&1]
if len(o)&1:
    print(sum(o)+sum(e)-o[0])
else:
    print(sum(o)+sum(e))
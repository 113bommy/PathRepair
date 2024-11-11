n = int(input())
a = list(map(int,input().split()))
if min(a)==max(a):print(max(a)-min(a),(a.count(min(a))-1)*a.count(min(a)) / 2)
else:print(max(a)-min(a),a.count(min(a))*a.count(max(a)))

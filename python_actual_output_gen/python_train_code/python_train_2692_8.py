a,b,c = map(int, input().split())
k = 0
if a>=c or b>=c:
    print(0)
    exit()
if a<=0 and b<=0:
    print(-1)
    exit()
if a<=0 or b<=0:
    s = max(a,b) - min(a,b)
    k += abs(s//min(abs(min(a,b)),abs(max(a,b))))
    if a<b:
        a+=k*min(abs(a),abs(b))
    else:
        b+=k*min(abs(a),abs(b))
while a<c and b<c:
    if a<b:
        a=b+a
    else:
        b=b+a
    k+=1


print(k)
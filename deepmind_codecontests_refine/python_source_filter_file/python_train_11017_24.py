n = int(input())
a = list(map(int, input().split()))
#符号が同じ場合、累積和的な感じでいける。
#全部負か全部正しかない。
#全部正の場合は、一番おっきいやつを一番左に足し、左から累積和
#全部負の場合は、一番ちっさいやつを右に足し、右から累積和
#また、負と正が両方含まれている場合は、どっちかに統一する
ans = []
if max(a) * min(a) < 0:
    if abs(max(a)) > abs(min(a)):
        for i in range(n):
            if i != a.index(max(a)):
                ans.append([a.index(max(a))+1, i+1])
                a[i] += max(a)
    else:
        for i in range(n):
            if i != a.index(min(a)):
                ans.append([a.index(min(a))+1, i+1])
                a[i] += min(a)
if max(a) > 0:
    #全部正
    for i in range(1,n):
        ans.append([i,i+1])
else:
    #全部負
    for i in range(n,0,-1):
        ans.append([i+1,i])
print(len(ans))
for i in range(len(ans)):
    print("{} {}".format(*ans[i]))

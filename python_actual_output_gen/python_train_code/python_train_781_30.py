d1, d2, d3 = map(int, input().split())
if max(d1, d2) + min(d1, d2) >= d3 and max(d1, d2) < d3 :
    print(min(d1, d2) + d3 + max(d1, d2))
elif max(d1, d2) + min(d1, d2) < d3:
    print(2*max(d1, d2) + 2*min(d1, d2))
else:
    print(2*min(d1,d2) + 2*d3)




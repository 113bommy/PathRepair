# # RED CODER # #
a, b, c = sorted(list(map(int, input().split())))
if a+b >= c:
    print(0)
else:
    print(c-(a+b) +1)
t = int(input())
while t != 0:
    s,a,b,c = map(int,input().split())
    number_of = int(s / c)
    offer = int((number_of/a) * b)
    totall = int(number_of + offer)
    print(totall)
    t -= 1
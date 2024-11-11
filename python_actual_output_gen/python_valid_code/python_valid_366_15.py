nb_friends, volume = [int(x) for x in input().split()]
mugs = [int(x) for x in input().split()]
if sum(mugs) - mugs[-1] > volume:
    print("NO")
else:
    print("YES")
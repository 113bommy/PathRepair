participants, pens, notebooks = list(map(int, input().split()))

if participants <= pens and participants <= notebooks:
    print("Yes")
else:
    print("No")

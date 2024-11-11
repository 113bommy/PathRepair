from itertools import*
a = [len(list(l)) for _, l in groupby(input())]
for p, q in zip(a[::2], a[1::2]):
    print("0 "*~-p, -~p//2 + q//2, p//2 + -~q//2, "0 "*~-1, end="")
from collections import*
f=lambda:sorted(Counter(input()).values())
print("YNEOS"[f()!=f()::2])
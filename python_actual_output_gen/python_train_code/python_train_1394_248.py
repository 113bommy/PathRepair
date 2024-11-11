a, b, c = map(int, input().split())
print("YNEOS"[not(a<=c<=b)::2])
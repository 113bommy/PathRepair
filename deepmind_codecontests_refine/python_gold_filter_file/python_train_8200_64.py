input();l=list(map(int,input().split()))
print("YNEOS"[len(l)!=len(set(l))::2])

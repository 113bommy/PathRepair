n, *l = open(0).read().split()
print("Yes" if len(set(l)) == len(l) and all(l[i][-1] == l[i+1][0] for i in range(n)) else "No")
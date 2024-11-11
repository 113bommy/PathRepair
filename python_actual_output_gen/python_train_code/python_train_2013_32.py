C=input()+input()
print("YNEOS"[sum([1 for i in range(3)if C[i]!=C[-i-1]])::2])
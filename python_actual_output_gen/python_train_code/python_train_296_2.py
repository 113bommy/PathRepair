# https://codeforces.com/problemset/problem/1215/B
n = int(input())
a = [1 if int(x)>0 else 0 for x in input().split()]
print(a)
nb_positif = 0
dp_pairs_positif = [0] * (n)
if a[0]==1:
    nb_positif = 1
    dp_pairs_positif[0] = 1

for x in range(1, n):
    if a[x]==1:
        nb_positif += 1
        dp_pairs_positif[x] = dp_pairs_positif[x-1] + nb_positif
    else:
        nb_positif = x - nb_positif
        dp_pairs_positif[x] = dp_pairs_positif[x-1] + nb_positif

print(str(int(n*(n+1)/2) - dp_pairs_positif[n-1]) + " " + str(dp_pairs_positif[n-1]))

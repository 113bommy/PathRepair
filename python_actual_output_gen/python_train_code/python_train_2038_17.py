n,k,c = map(int,input().split())
s = input()
fro = []
bac = []

for i in range(n):
    if s[i] == "o" and (len(fro) == 0 or fro[-1]+c < i):
        fro.append(i)
    if s[n-i-1] == "o" and (len(bac) == 0 or bac[-1]-c > n-i):
        bac.append(n-i-1)

for i in range(k):
    if fro[i] == bac[-i-1]:
        print(fro[i]+1)

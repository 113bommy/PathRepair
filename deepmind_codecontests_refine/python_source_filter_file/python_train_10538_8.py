from pprint import pprint
n, m, p = map(int, input().split())
data = list(map(lambda x: int(x) % p , input().split()))
datb = list(map(lambda x: int(x) % p , input().split()))
#print(data)
#print(datb)
for i in range (n):
    if data[i] != 0:
        inda = i
        break
for i in range (m):
    if datb[i] != 0:
        indb = i
        break
#print(inda, indb)
print(n*indb + inda)

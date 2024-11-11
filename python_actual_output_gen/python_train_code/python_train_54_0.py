n, c = map(int, input().split())
l = list(map(int, input().split()))
bigest_dec = 0
bigest_dec_index = 0
for i in range(n-1):
    if l[i] - l[i+1] > bigest_dec:
        bigest_dec = l[i] - l[i+1]
        bigest_dec_index = i
        
if not(bigest_dec-c>0):
    print(bigest_dec-c)
else:
    print(0)
    
n = int(input())
cities = list(map(int , input().split()))
dict = {}
m = 1000000009
for i in range(0,n):
    if cities[i]<m:
        m = cities[i]
        ind = i+1
    if cities[i] not in dict:
        dict[cities[i]] = 1 
    else:
        dict[cities[i]] += 1 
if dict[m]>1:
    print('Stil Rozdil')
else:
    print(ind)


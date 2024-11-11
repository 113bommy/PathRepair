n,m = list(map(int, input().split()))
mat,sat = [n//5] * 5,[m//5] * 5
for i in range(n%5):
    mat[i]+=1
for j in range(m%5):
    sat[j]+=1

print(sum([mat[i] * sat[5-i-2] for i in range(5)]))

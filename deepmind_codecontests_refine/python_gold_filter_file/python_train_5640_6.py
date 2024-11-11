n = int(input())
li = [0 for i in range(n+1)]
for i in range(n-1) :
    a , b = map(int , input().split())
    li[a] += 1
    li[b] += 1
print('no' if 2 in li else 'yes')
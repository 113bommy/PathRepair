l, r= map(int, input().split())
print('YES')
for i in range(l, r-l+1, 2):
    print(i,i+1, sep=' ')
    
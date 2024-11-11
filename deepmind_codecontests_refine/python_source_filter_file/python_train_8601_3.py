k, p = map(int, input().split())
c = 0
a = ['00','11','22','33','44','55','66','77','88','99']
i = 0
while len(a) < k + 10:
    i+=1
    for j in range(1,10):
        a.append(str(i) + a[j%10] + str(i)[::-1])
print(sum(map(int,a[:k+1])) % p)
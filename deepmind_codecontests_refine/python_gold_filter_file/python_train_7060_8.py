N=int(input())
inlis=[int(i) for i in input().split()]
csum=[0]*(N+1)
for i, v in enumerate(inlis, start=1): csum[i] = csum[i-1] + v

i, k = 1, 3
resmin = 9223372036854775807
# print(csum)
for j in range(2, N-1):
    while abs((csum[i]-csum[0]) - (csum[j]-csum[i])) > abs((csum[i+1]-csum[0]) - (csum[j]-csum[i+1])): i += 1
    while abs((csum[k]-csum[j]) - (csum[N]-csum[k])) > abs((csum[k+1]-csum[j]) - (csum[N]-csum[k+1])): k += 1
    # print("p{} q{} r{} s{}".format(csum[i]-csum[0], csum[j]-csum[i], csum[k]-csum[j], csum[N]-csum[k]))
    # minkamo = max(csum[i]-csum[0], csum[j]-csum[i], csum[k]-csum[j], csum[N]-csum[k]) - min(csum[i]-csum[0], csum[j]-csum[i], csum[k]-csum[j], csum[N]-csum[k])
    # print(i,j,k, minkamo)
    resmin = min(resmin, max(csum[i]-csum[0], csum[j]-csum[i], csum[k]-csum[j], csum[N]-csum[k]) - min(csum[i]-csum[0], csum[j]-csum[i], csum[k]-csum[j], csum[N]-csum[k]))

print(resmin)

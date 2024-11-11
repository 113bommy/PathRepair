case = int(input("h"))
times=list(range(case))
for i in range(case):
    h,m = map(int, input().split())
    times[i]=[h,m]

for i in range(case):
    total = 60*24 - times[i][1] - times[i][0]*60
    print(total)
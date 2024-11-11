t = int(input())

pows = []
for i in range(40):
    pows.append(str(2**i))

answer = []

for _ in range(t):
    n = input()
    ans = 10**18
    for num in pows:
        ncopy = n
        count = 0
        for c in num:
            if c in ncopy:
                ind = ncopy.find(c)
                count += ind
                ncopy = ncopy[ind+1:]
            else:
                ind = len(ncopy)
                count += ind + 1
                ncopy = ""
        count += len(ncopy)
        ans = min(ans, count)
    print(ans)
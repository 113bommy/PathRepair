# print ("Input n, l, r, and x")
vals = input().split()
n = int(vals[0])
l = int(vals[1])
r = int(vals[2])
x = int(vals[3])

# print ("Input the n problem values")
plist = input().split()
pbs = []
for i in range(n):
    pbs.append(int(plist[i]))

if n==1:
    print(0)
if n==2:
    if pbs[0] + pbs[1]>=l and pbs[0]+pbs[1]<=r and abs(pbs[0]-pbs[1])>=x:
        print(1)
    else:
        print(0)
else:    # At least three problems--check all subsets
    answer = 0
    allmasks = 1 << n
    for i in range(allmasks):  # Loop over all possible masks
        pbnum = 0
        pbsum = 0
        pbmin = 1000001
        pbmax = 0
        for j in range(n):  # Loop over each position of a bit
            if (i & (1 << j) > 0):   # Is the jth bit present in the mask?
                pval = pbs[j]
                pbnum += 1
                pbsum += pval
                if pval > pbmax:
                    pbmax = pval
                if pval < pbmin:
                    pbmin = pval
        #  Is it a good problem set?
        if (pbnum >= 2 and pbsum >=l and pbsum <= r and pbmax - pbmin>=x):
            answer += 1
    print (answer)
                

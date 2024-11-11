inp = [int(x) for x in input().split()]

wt_limark = inp[0]
wt_bob = inp[1]

for i in range(1, 100):
    if wt_limark * 3  > wt_bob * 2:    
        print(i)
        break
    else:
        wt_limark += wt_limark * 3
        wt_bob += wt_bob * 2
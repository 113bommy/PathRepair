import sys

n = int(input())
aa = list(map(int, input().split()))
aa.sort()

if all(a == 0 for a in aa):
    print("cslnb")
    sys.exit(0)

# Check for more than one pair
paircount = 0
for i in range(len(aa)-1):
    if aa[i+1] == aa:
        paircount += 1
        if aa[i] == 0 or i > 0 and aa[i-1] == aa[i]:
            paircount += 1
if paircount > 1:
    print("cslnb")
    sys.exit(0)

moves = 0
for i in range(len(aa)):
    moves += aa[i] - i

if moves % 2 == 0:
    print("cslnb")
else:
    print("sjfnb")



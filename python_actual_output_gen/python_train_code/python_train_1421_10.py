inputer = input()
inp = inputer.split()

inp = [ int(x) for x in inp ]

# The first line contains four integers a, b, c, d (250 ≤ a, b ≤ 3500, 0 ≤ c, d ≤ 180).
#
# It is guaranteed that numbers a and b are divisible by 250 (just like on any real Codeforces round).


def point(p,t):
    return max((3*p / 10), ((p-(p/250))*t) )

mp = point(inp[0], inp[2])

vp = point(inp[1], inp[3])

if mp > vp:
    print("Misha")
elif mp < vp:
    print("Vasya")
else:
    print("Tie")
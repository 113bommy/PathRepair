test_cases = int(input())
soln = []
while test_cases != 0:
    ac, bc, c, r = [int(_) for _ in input().split(" ")]
    if ac < bc:
        a = ac
        b = bc
    else:
        a = bc
        b = ac
#now we know a is the smaller one out of a and b
    left_pt = c - r
    right_pt = c + r
    ans = (b-a) - (min(b,right_pt)-max(a,left_pt))
    soln.append(ans)
    test_cases -= 1

for x in soln: print(x)

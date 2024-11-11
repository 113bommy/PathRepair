in0 = int(input())
in1, in2, in3 = 0, 0, 0
in4 = [int(x) for x in input().split()]
for x in in4:
    if x >= in1:
        in1 = x
        in2 += 1
    else:
        in1 = x
        if in2 > in3:
            in3 = in2
        in2 = 1
if in2 > in3:
    in3 = in2
print(in3)
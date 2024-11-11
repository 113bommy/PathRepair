A,B,C = [int(v) for v in input().split()]
print(max(C-(A-B),0))
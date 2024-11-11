# Pradnyesh Choudhari
# Sat Jul 18 22:51:30 2020

l = list(map(int, input().split()))
print(min((l[1] * l[2]) // l[-2], l[3] * l[4], l[-3] / l[-1]) // l[0])


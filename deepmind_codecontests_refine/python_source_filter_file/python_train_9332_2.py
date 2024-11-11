m=[int(i) for i in input().split()]
a= [int(i) for i in input().split()]
b= [int(i) for i in input().split()]
r =[[max(ax*bx for bx in b)] for ax in a]
r.sort()
print (r[-2])
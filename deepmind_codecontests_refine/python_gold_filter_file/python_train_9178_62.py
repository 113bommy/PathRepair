# B
H,L=list(map(int, input().split()))
#print(H,L)
R=(L**2+H**2)/(2*H)
#print(R-H)
print("%.7f" % (R-H))

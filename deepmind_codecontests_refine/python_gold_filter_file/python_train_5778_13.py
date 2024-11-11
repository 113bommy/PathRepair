sides = list(map(int, input().split()))
c0 = (0,0)
c1 = (sides[0], 0)
c2 = (c1[0] + sides[1]/2, 0.5*(3**0.5)*sides[1])
c3 = (c2[0] - sides[2]/2, c2[1] + sides[2]*0.5*(3**0.5))
c4 = (c3[0]-sides[3], c3[1])
c5 = (c4[0]-sides[4]*0.5, c4[1]-sides[4]*0.5*(3**0.5))
c6 = (c5[0]+sides[5]*0.5, c5[1]-sides[5]*0.5*(3**0.5))
#print(c3)
#print(c6)

area1 = (c0[0]*c1[1]+c1[0]*c2[1]+c2[0]*c3[1]+c3[0]*c4[1]+c4[0]*c5[1]+c5[0]*c0[1])
area2 = (c0[1]*c1[0]+c1[1]*c2[0]+c2[1]*c3[0]+c3[1]*c4[0]+c4[1]*c5[0]+c5[1]*c0[0])

print(int(round((area1-area2)/2/(3**0.5)*4)))



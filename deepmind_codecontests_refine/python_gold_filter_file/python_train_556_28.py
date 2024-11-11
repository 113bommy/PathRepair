r1=list(map(int, input().split()))
r2=list(map(int, input().split()))
r3=list(map(int, input().split()))
r1[0]=(2*r2[2]-r1[1]+r2[0])//2
r2[1] = (r1[1]+2*r1[2]-r2[0])//2
r3[2] = (r1[1]+r2[0])//2
print(*r1)
print(*r2)
print(*r3)

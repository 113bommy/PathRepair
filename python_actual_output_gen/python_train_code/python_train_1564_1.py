a,b,c,d = map(int,input().split())
def countt(z):
	if b+c<= z:
		return 0 
	if a+b >z:
		return (b-a+1)*(c-b+1)
	xstart = z-c+1
	xfin = min(b, z+1-b)
	ilo = ((abs(xstart-xfin)+1)*(c+1-(z-xstart+1)+c+1-(z-xfin+1))//2)
	ilo += ((b-xfin)*(c-b+1))
	return ilo
wyn = 0
for z in range(c,d+1):
	wyn += countt(z)
print(wyn)

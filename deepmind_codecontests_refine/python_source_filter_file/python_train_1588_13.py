
import sys,math
I=sys.stdin.readline
ans=""

for _ in range(int(I())):
		n=2*int(I())
		angle=math.radians(((n-2)*180/n)/2)
		ob=0.5*round(math.tan(angle),2)
		ans+=str(ob+ob)+"\n"


print(ans)
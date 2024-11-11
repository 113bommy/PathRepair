def compute_gcd(x, y):

   while(y):
       x, y = y, x % y
   return x

def compute_lcm(x, y):
   lcm = (x*y)//compute_gcd(x,y)
   return lcm

def solve():
    x, y, a, b = I()
    lo = a//compute_lcm(x,y)
    hi = b//compute_lcm(x,y)

    print(hi - lo + 1)

if __name__ == "__main__":
	# editor()
	tc=1
	# tc=int(input())
	I=lambda:list(map(int,input().split()))
	for t in range(tc):
		solve()
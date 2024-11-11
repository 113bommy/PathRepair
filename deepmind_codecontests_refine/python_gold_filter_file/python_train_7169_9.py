# AOJ 0021: Parallelism
# Python3 2018.6.15 bal4u

EPS = 1e-11

def dot(a, b):
	return a.real*b.real + a.imag*b.imag

def cross(a, b):
	return a.real*b.imag - a.imag*b.real
	
def norm(a):
	return a.real**2 + a.imag**2
	
def project(line, p):
	base = line[1]-line[0]
	r = dot(p-line[0], base) / norm(base)
	return line[0] + base*r
	
def symmetric_Point(line, p):
	return p + 2*(project(line, p)-p)

def isParallelLL(line1, line2):
	t = cross(line1[1]-line1[0], line2[1]-line2[0])
	return -EPS <= t and t <= EPS


for _ in range(int(input())):
	p = list(map(float, input().split()))
	p1 = complex(p[0], p[1])
	p2 = complex(p[2], p[3])
	p3 = complex(p[4], p[5])
	p4 = complex(p[6], p[7])
	print('YES' if isParallelLL([p1,p2], [p3,p4]) else 'NO')

def solve(n):
    for _ in range(n):
        x = int(input())
        c1 = x//3
        b1 = x - 2*c1
        c2 = c1 + 1
        b2 = x - 2*c2
        if abs(c1 - b1) < abs(c2 - b2):
    	    print(b1,c1)
        else:
    	    print(b2,c2)
def main():
	n = int(input())
	solve(n)

if __name__ == '__main__':
	main()
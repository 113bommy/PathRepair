if __name__ == '__main__':
    n = int(input())
    l, r = 1, 10 ** 9
    x, mid = 0, 0
    while l <= r:
        mid = (l+r)//2
        if 3*mid*(mid-1) <= n:
            l = mid + 1
            x = mid
        else:
            r = mid - 1
    a, b = (n-3*x*(x-1))//x, (n-3*x*(x-1)) % x
    q, w = 0, 0
    if a == 0:
        q, w = 2*x, 0
        if b == 0:
            q = 2*x - 1
        else:
            q += -b
            w += 2*b
    elif a == 1:
        q, w = x-2*b, 2*x
    elif a == 2:
        q, w = -x-b, 2*x-2*b
    elif a == 3:
        q, w = -2*x+b, -2*b
    elif a == 4:
        q, w = -x+2*b, -2*x
    elif a == 5:
        q, w = x+b, -2*x+2*b
    print(q, w)

	 	 	  	 		 	  	    	 	 							
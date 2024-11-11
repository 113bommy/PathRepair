def stuff(n,b,p):
    print((b-1)*(b*2+1), p*n)
n, b, p = input().strip().split()
stuff(int(n),int(b),int(p))
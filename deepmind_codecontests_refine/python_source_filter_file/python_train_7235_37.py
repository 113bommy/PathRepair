if __name__ == "__main__":

    n = int( input() )
    b = [ int(x) for x in input().split() ]

    res = b[0]
    for i in range(1,n):
        res += abs( b[i] - b[i-1] )

    print( res )
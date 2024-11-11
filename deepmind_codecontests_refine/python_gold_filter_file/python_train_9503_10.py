import sys
#from collections import deque #Counter


def rl():
    return sys.stdin.readline().strip()

def pr( something ):
    sys.stdout.write( str(something) + '\n')
def pra( array ):
    sys.stdout.write( ' '.join([str(x) for x in array]) + '\n')


def solve(array):
    return array


if __name__ == '__main__':

    N = int( rl() )
    H = N//2

    #num_pairings = N choose H
    def fact(n):
        return 1 if n <= 1 else n*fact(n-1)

    num_pairings = fact(N)//(2*fact(H)**2)
    #print(f'np[{N}]={num_pairings}')

    #now within each of those how many ways to make circles???
    if True:
        ncirc = 1 if H <= 2 else fact(H-1)
        #print(f'ncirc={ncirc}')
        pr(num_pairings*ncirc*ncirc)
    else:
        ncirc = [0]*(H+1)
        if H >= 1:
            ncirc[1] = 1
        if H >= 2:
            ncirc[2] = 1
        if H >= 3:
            ncirc[3] = 1
        for i in range(4,H+1):
            ncirc[i] = ncirc[i-1] * (i//2)
        #print(f'ncirc = {ncirc}')
        

        pr(num_pairings*ncirc[-1]*ncirc[-1])


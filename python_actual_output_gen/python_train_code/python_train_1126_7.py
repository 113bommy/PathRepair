masukan = [int(item) for item in input().split(" ")]
n = masukan[0] # vertex
m = masukan[1] # edges

def getMin():
    if n/m <= 2:
        return 0
    else:
        return n - (m*2)

def getMax():
    numEdge = 0
    for i in range(2,n+1):
        # print("vertex ke: ",i)
        if numEdge < m:
            numPosEdge = i*(i-1)/2
            numEdge = numPosEdge
            # print("possible edge: ",numPosEdge)
            # print("edge skrg: ",numEdge)
        else:
            return n-(i-1)
    # return n-i
if n == 0:
    print(0,0)
elif m == 0:
    print(n,n)
elif m >= n*(n-1)/2:
    print(0,0)
else:
    print(getMin(), getMax())
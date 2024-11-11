n = int(input())

ini = 2
 
lpre = 1

lnext = 2

m=1

for i in range(1, n+1):

        m = i

        print((m*m*lnext*lnext-ini)//lpre)

        ini=m*lnext
        m=0
        lnext = lnext + 1
        lpre = lpre + 1
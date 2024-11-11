n = int(input())
M = 998244353

def fastfrac(a,b):
    numb = pow(b,M-2,M)
    return ((a%M)*(numb%M))%M




if n<3: num = 1
else:

    oddsum = 1
    evensum = 1
   
 #   arr = [1]*(n+1)



    i = 0
    for i in range(2,n+1):
        if i%2==1: 
            num = evensum
            oddsum  += num
#            oddsum %=M
        else:
            num = oddsum
            evensum += num
#            evensum %=M
      


#print(num)

divisor = pow(2,n,M)





print(fastfrac(num,divisor))




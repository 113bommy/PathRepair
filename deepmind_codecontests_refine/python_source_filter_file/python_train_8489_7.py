n, k, t = input().split()
n = int(n)
k = int(k)
t = int(t)

s = (n*k*t)/100
for i in range(0,n):
    if s>k:
        print(k,end=" ")
        s = s - k
    elif s<k and s> 0:
        print(int(s),end=" ")
        s = 0
    else:
        print(0, end=" ")


    			  		  				 	 		   		 	 	
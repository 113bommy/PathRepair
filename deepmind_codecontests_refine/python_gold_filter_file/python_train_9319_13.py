n = int(input())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

a = 0
b = 0
for i in range(len(l1)):
    a = a | l1[i]
    b = b | l2[i]

print(a + b)
 			 	 	  		  				  		 		    	
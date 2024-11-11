import math


a1, a2, a3, a4, a5, a6 = map(int, input().split())
'''if a1 != a3:
    if a2 == a4:
        a1, a2, a3, a4, a5, a6 = a2, a3, a4, a5, a6, a1
    elif a3 == a5:
        a1, a2, a3, a4, a5, a6 = a3, a4, a5, a6, a1, a2
x = math.sqrt(3) / 2
l1 = a1 / 2 + a3 / 2 + a2
l2 = a4 / 2 + a6 / 2 + a5
s1 = (l1 + a2) / 2 * x * a1
s2 = (l2 + a5) / 2 * x * a6
print(int((s1 + s2) / (x * 0.5)))
'''
l = a1 + a2 + a3
print(l * l - a1 * a1 - a2 * a2 - a3 * a3)

	 	 	 	  	 		 		  	 		    					
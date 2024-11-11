n = int(input())
ans = []
while n:
    n += -1
    p, q, b = map(int, input().split())
    if p * pow(b, 10, q) % q: ans.append("Infinite")
    else: ans.append("Finite")
for _ in ans: print(_)
						 	 	 	 		 			 	 			  				
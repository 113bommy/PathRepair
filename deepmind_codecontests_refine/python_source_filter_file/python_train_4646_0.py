from operator import itemgetter

def main():
	n = int(input())
	tv = [(-1, -1, 0)]
	for i in range(1, n+1):
		li, fi = map(int, input().split(' '))
		make_tuple = (li, fi, i)
		tv.append(make_tuple)
	tv.append((10000000000, 10000000000, n+1))
	tv.sort()
	
	for i in range(1, n+1):
		tp = tv[i-1]
		tc = tv[i]
		tn = tv[i+1]
		
		if(tc[1] <= tp[1] or (tc[0] >= tn[0] and tc[1] <= tn[1]) or (tp[1]+1 >= tn[0] and tc[0] <= tn[1])):
			print(tc[2])
			break
	else:
		print("-1")						
				 		

if __name__ == "__main__":
	main()	
			

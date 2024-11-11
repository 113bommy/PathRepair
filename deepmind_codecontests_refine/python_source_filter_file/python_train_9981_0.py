def solve(y,m,d):
	if y<1868 or (y==1868 and m<9) or (y==1868 and m==9 and d<8):
		print("pre-meiji")
	elif 1869<y<1912 or (y==1868 and 7<m) or (y==1868 and m==9 and 8<=d) or (y==1912 and m<7) or(y==1912 and m==7 and d<=29):
		print("meiji %d %d %d"%(y-1868+1,m,d))
	elif 1913<y<1925 or (y==1912 and 7<m) or (y==1912 and m==7 and 25<=d) or (y==1926 and m<12) or (y==1926 and m==12 and d<=24):
		print("taisho %d %d %d"%(y-1912+1,m,d))
	elif 1927<y<1989 or (y==1926 and 12<m) or (y==1926 and m==12 and 25<=d) or (y==1989 and m<1) or (y==1989 and m==1 and d<=7):
		print("showa %d %d %d"%(y-1026+1,m,d))	
	else:
		print("heisei %d %d %d"%(y-1989+1,m,d))


while True:
	try:
		y,m,d=map(int,input().split())
		solve(y,m,d)
	except EOFError:
		break
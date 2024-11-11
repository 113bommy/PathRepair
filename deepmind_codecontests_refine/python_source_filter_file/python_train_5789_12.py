def check(a,c):
	if a[(c+1)%4][0]==0 and a[(c+2)%4][1]==0 and a[(c+3)%4][2]==0:
		return False
	else:
		return True

def src(a):
	f = True
	k = True
	for i in range(4):
		if a[i][3]==1:
			if (a[i][0]==1 or a[i][1]==1 or a[i][2]==1):
						return "YES"
			k = False
			f = f and check(a,i)
	if k:
		return "NO"
	if f:
		return "YES"
	else:
		return "NO"




def test():
    s = []
    a = [[],[],[],[]]
    for i in range(4):
        s.append(input())
    for i in range(4):
        for j in range(len(s[i])):
            if s[i][j]!=" ":
                a[i].append(int(s[i][j]))
    return src(a)


if __name__== "__main__":
    print(test())
            

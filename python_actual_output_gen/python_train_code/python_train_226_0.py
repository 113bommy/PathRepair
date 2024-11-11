ch = input().split('b')

mod = 1000000007
m = len(ch) -1 
s = 0
t = 0
while ( m >= 0 ) :
	if ch[m] != '' :
		k = ch[m].count('a')
		if k != 0 :
			t = (k*(1+t))%mod
			s = (s + t)%mod

	m -= 1

print(s)







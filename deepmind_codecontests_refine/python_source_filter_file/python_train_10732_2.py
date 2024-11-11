n, m  = map(int , input().split())
s = str(input())
t = str(input())
if s.count('*') == 0 and s!= t :
	print("NO")
elif s.count('*') == 0 and s== t :
	print("YES")
elif s.count('*')!=0 :
	k = int(s.find('*'))
	s1 = s[::-1]
	t1 = t[::-1]
	print(t1, s1, s[0:k], t[0:k], s[0:n-k-1], t1[0:n-k-1], k , n-k-1)
	if s[0:k]==t[0:k] and s1[0:n-k-1]==t1[0:n-k-1] and m-n>=-1:
		print(1)
		print("YES")
	else:
		print(2)
		print("NO")
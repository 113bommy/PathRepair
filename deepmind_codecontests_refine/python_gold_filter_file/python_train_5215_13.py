def main():
	s=list(map(int,list(input())))

	cnt=0
	add=0
	cnt_to_3=0
	for i in range(len(s)):
		add+=s[i]
		cnt_to_3+=1
		if s[i]%3==0 or add%3==0 or cnt_to_3==3:
			cnt+=1
			add=0
			cnt_to_3=0
	print(cnt)

main()
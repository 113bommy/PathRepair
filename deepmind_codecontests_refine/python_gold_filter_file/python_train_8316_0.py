ans=""
while True:
	try:
		info=input()
	except:
		break
	if ans!="":
		ans+="\n"
	info_2=info.split()
	ans+=str(int(info_2[0])+int(info_2[1]))
print(ans)
for _ in range(int(input())):
	x=int(input())
	s=list(input())

	leng=len(s)
	times=1
	till=0
	ended=0

	while(times<=x and leng<x):
		till=leng
		for i in range(int(s[times-1])):
			if(leng>=x):
				leng+=(int(s[times-1])-i-1)*(till-times)
				break
			s.extend(s[times:till])
			leng+=till-times
		times+=1

	#print(times,leng)

	while(times<=x):
	#	print(times,leng,int(s[times-1])-1,(leng-times))
		leng+=(int(s[times-1])-1)*(leng-times)
		times+=1
	leng=leng%(1000000007)
	print(leng)


# from selenium import webdriver
# browser = webdriver.Chrome(executable_path='C:\\Users\\Dell\\.wdm\\drivers\\chromedriver\\79.0.3945.36\\win32\\chromedriver.exe')
# browser.get("http://cbseresults.nic.in/ctetD19/ctetD19.htm")

# start=123026000

# while True:
# 	username = browser.find_element_by_xpath("//input[@name='regno']")
# 	submit = browser.find_element_by_xpath("//input[@name='B1']")
# 	username.clear()
# 	username.send_keys(str(start))
# 	submit.click()
# 	html = browser.page_source
# 	if(html.find("VASANT")!=-1):
# 		print("hello")
# 		break
# 	browser.back()
# 	start+=1
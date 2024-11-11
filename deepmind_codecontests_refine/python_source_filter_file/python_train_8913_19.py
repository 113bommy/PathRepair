import webbrowser
if True == False:
	url = input()

	#webbrowser.get(using='firefox')

	#webbrowser.register('firefox',('mozilla'))
	while True :
		webbrowser.open(url)
else:
	n = int(input())
	l = [int(i) for i in input().split()]
	a = l.count(1)
	b = l.count(2)
	print(min(a,b)+(max(a,b)-min(a,b))//3)

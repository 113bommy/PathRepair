ddi = { 'purple':'power ','green':'time ', 'blue':'space', 'orange':'soul', 'red':'reality', 'yellow':'mind'}
n = int(input())
for i in range(n):
	m = input()
	del ddi[m]
print(len(ddi))
for key in ddi.keys():
	print(ddi[key])
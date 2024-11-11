ddi = { 'purple':'Power ','green':'Time ', 'blue':'Space', 'orange':'Soul', 'red':'Reality', 'yellow':'mind'}
n = int(input())
for i in range(n):
	m = input()
	del ddi[m]
print(len(ddi))
for key in ddi.keys():
	print(ddi[key])
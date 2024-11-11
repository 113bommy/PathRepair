def ifLeap(year):
	if(year %100 == 0):
		if(year%400 == 0):
			return True
	elif(year%4 == 0):
		return True
	return False
year1,month1,day1 = map(int,input().split(':'))
year2,month2,day2 = map(int,input().split(':'))

month =[]
jan = []
for i in range(1,32):
	jan.append(i)
month.append(jan)
feb = []
for i in range(32,61):
	feb.append(i)
month.append(feb)
mar = []
for i in range(61,92):
	mar.append(i)
month.append(mar)
apr =[]
for i in range(92,122):
	apr.append(i)
month.append(apr)
may = []
for i in range(122,153):
	may.append(i)
month.append(may)
jun = []
for i in range(153,183):
	jun.append(i)
month.append(jun)
jul = []
for i in range(183,214):
	jul.append(i)
month.append(jul)
aug = []
for i in range(214,245):
	aug.append(i)
month.append(aug)
sep =[]
for i in range(245,275):
	sep.append(i)
month.append(sep)
oct = []
for i in range(275,306):
	oct.append(i)
month.append(oct)
nov = []
for i in range(306,336):
	nov.append(i)
month.append(nov)
dec = []
for i in range(336,367):
	dec.append(i)
month.append(dec)

rday1 = month[month1-1][day1-1]
rday2 = month[month2-1][day2-1]

if(year2 < year1):
	year1,year2 = year2,year1
	rday1,rday2 = rday2,rday1
elif(year2 == year1):
	if(rday2 < rday1):
		year1,year2 = year2,year1
		rday1,rday2 = rday2,rday1
difday = 0
difyear = year2 - year1
if(rday2 < rday1):
	difday = 366-rday1 + rday2
	difyear -= 1
else :
	difday = rday2 - rday1
if(not ifLeap(year1)):
	if rday1<60 and rday2 > 60 :
		difday -= 1
	elif(rday1 > rday2 and rday1 <60):
		difday -= 1
if(not ifLeap(year2)):
	if(rday2 < rday1 and rday2 > 60):
		difday -= 1
difday += difyear * 365
for i in range(year1+1,year2):
	if(ifLeap(i)) :
		difday += 1
print (difday)

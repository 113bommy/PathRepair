mp = {
	"0" : "",
	"1" : "",
	"2" : "2",
	"3" : "3",
	"4" : "322",
	"5" : "5",
	"6" : "53",
	"7" : "7",
	"8" : "7222",
	"9" : "7332"
}
s = [x for x in input()]
a = []
for i in s:
	a.append(mp[i])
a = list(''.join(a))
a.sort(reverse=True)
print(''.join(a))
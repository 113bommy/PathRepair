s = input()
l = ["","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
l3 = ["one","two","three","four","five","six","seven","eight","nine"]
l1 = {"0":"zero","1":"one","2":"two","3":"three","4":"four","5":"five","6":"six","7":"seven","8":"eight","9":"nine"}
l2 = {"10":"ten","20":"twenty","30":"thirty","40":"forty","50":"fifty","60":"sixty","70":"seventy","80":"eighty","90":"ninety"}
d = {
	"11":"eleven",
	"12":"twelve",
	"13":"thirteen",
	"14":"forteen",
	"15":"fifteen",
	"16":"sixteen",
	"17":"seventeen",
	"18":"eighteen",
	"19":"nineteen"}
	
if len(s)==1:print(l1[s])
elif len(s)==2:
	if s.count("0")==1:
		print(l2[s])
	elif s[0]=="1":
		print(d[s])	
	else:
		print(l[int(s)//10]+"-"+l3[(int(s)%10)-1])
			